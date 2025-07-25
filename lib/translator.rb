require 'tree_stand'
require 'tree_sitter'
require 'nokogiri'
require 'yaml'

class Translator
  class TranslationError < StandardError
  end

  def initialize
    load_rules
  end

  def java
    @java ||= TreeStand::Parser.new('java')
  end

  def python
    @python ||= TreeStand::Parser.new('python')
  end

  def translation
    @translation ||= TreeStand::Parser.new('bugfix-translation')
  end

  def load_rules
    @rules = {}

    Dir.glob('_data/languages/**/*.yml') do |file|
      lang = file.pathmap('%-1d').to_sym
      node = file.pathmap('%n').to_sym

      @rules[lang] ||= {}

      rules = YAML.safe_load_file(file, symbolize_names: true)
      @rules[lang][node] = rules
    end
  end

  # Returns translation tree
  def translate(lang, filename)
    parser = lang == :java ? java : python

    code = File.read(filename)
    tree = parser.parse_string(code)

    translate_tree(lang, tree.root_node)
  end

  def tree_to_xml_doc(tree)
    make_xml(tree)
  end

  private

  def make_xml_inner(xml, t)
    attrs = {
      type: t[:type],
      pos: t[:pos],
      length: t[:length]
    }
    attrs[:label] = t[:fields][:text] if t[:fields].keys == [:text]
    xml.tree(**attrs) do
      if !attrs.key?(:label)
        t[:fields].each do |k, v|
          make_xml_inner(xml, v)
        end
        t[:children].each do |child|
          make_xml_inner(xml, child)
        end
      end
    end
  end

  def make_xml(t)
    builder = Nokogiri::XML::Builder.new do |xml|
      make_xml_inner(xml, t)
    end

    builder.doc
  end

  def build_node(lang, match, node)
    case node.type
    when :variable
      key = node.each_named.to_a.last.text
      matches = match[key]
      return nil unless matches # there was no match and it was optional

      raise TranslationError, "Multiple matches for #{key}" if matches.size != 1

      return translate_tree(lang, matches.first)
    when :variable_text
      key = node.each_named.to_a.last.text
      matches = match[key]
      raise TranslationError, "Multiple matches for #{key}" if matches.size != 1

      return matches.first.text
    end

    raise TranslationError, "Unknown type #{node.type}" unless node.type == :node

    range = match['ROOT'].first.range
    result = {
      type: node[:type].text,
      fields: {},
      children: [],
      pos: range.start_byte,
      length: range.end_byte - range.start_byte
    }

    node.each_named do |child|
      if child.type == :splat
        key = child.each_named.to_a.last.text
        result[:children] += (match[key] || []).map { |n| translate_tree(lang, n) }.compact
      end
      next if child.type != :field

      field_name = child[:name].text
      val_node = child[:value]
      val = build_node(lang, match, val_node)
      result[:fields][field_name] = val if val
    end

    result
  end

  def translate_tree(lang, node)
    type = node.type
    rules = @rules[lang][type]

    raise TranslationError, "No rules for type #{type} #{node.sexpr}" unless rules

    rules.each do |rule|
      captures = find_match(node, rule[:source] + ' @ROOT')

      next unless captures

      return nil if rule[:skip] # This rule means match should be ignored

      construct_tree = translation.parse_string(rule[:construct])

      return build_node(lang, captures, construct_tree.root_node)
    end

    raise TranslationError, "No #{lang} rule matched #{node.sexpr}"
  end

  def find_match(n, q)
    query = TreeSitter::Query.new(n.tree.parser.ts_language, q)

    cursor = TreeSitter::QueryCursor.new
    cursor.max_start_depth = 0

    one_consumed = false

    caps = {}

    cursor
      .matches(query, n.ts_node, n.tree.document)
      .each do |match|
      if one_consumed
        pp n
        raise TranslationError, "Multiple matches for #{q} #{match}"
      end

      match.captures.each do |capture|
        k = query.capture_name_for_id(capture.index)
        caps[k] = [] unless caps.key?(k)
        caps[k] << TreeStand::Node.new(n.tree, capture.node)
      end

      one_consumed = true
    end

    one_consumed && caps
  end
end
