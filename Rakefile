require "minitest/test_task"
require 'yaml'
require 'json'
require 'rake/clean'
require 'tempfile'
require 'open3'

require_relative './lib/translator.rb'

Minitest::TestTask.create

task :default => :test

namespace :examples do
  directory '_data/examples'
  CLEAN.include('_data/examples')

  task all: ['defects4j:generate', 'quixbugs:generate']

  def print_example_yml(name, language, before, after)
    text_diff = `diff -u -Lbefore -Lafter #{before} #{after}`

    tree_diff = nil
    before_tree = nil
    after_tree = nil
    t = Translator.new
    Tempfile.create do |xml_before|
      Tempfile.create do |xml_after|
        out, err, status = Open3.capture3("bundle exec rake translate:#{language}:json[#{before}]")
        if err.include?("TranslationError")
          puts "Skipping: #{err}"
          next
        end
        unless status.success?
          puts "ERROR translating #{before}"
          puts "STDOUT:"
          puts out
          puts "STDERR:"
          puts err
          raise "Error"
        end

        before_tree = JSON.parse(out, symbolize_names: true)
        File.write(xml_before.path, t.tree_to_xml_doc(before_tree).to_xml)

        out, err, status = Open3.capture3("bundle exec rake translate:#{language}:json[#{after}]")
        if err.include?("TranslationError")
          puts "Skipping: #{err}"
          next
        end
        unless status.success?
          puts "ERROR translating #{after}"
          puts "STDOUT:"
          puts out
          puts "STDERR:"
          puts err
          raise "Error"
        end

        after_tree = JSON.parse(out, symbolize_names: true)
        File.write(xml_after.path, t.tree_to_xml_doc(after_tree).to_xml)

        tree_diff = `gumtree cluster -g xml #{xml_before.path} #{xml_after.path}`
      end
    end

    return unless tree_diff

    yaml = {
      language: language.to_s,
      before_tree:,
      after_tree:,
      text_diff:,
      tree_diff:
    }

    File.write(name, yaml.to_yaml(stringify_names: true))
  end

  namespace :defects4j do
    D4J_EXAMPLE_DIRS = FileList['inputs/defects4j/**/*.java.after']
    D4J_EXAMPLE_DATA = D4J_EXAMPLE_DIRS.pathmap('%-3d').gsub('/', '_').map { |s| "_data/examples/#{s}.yml" }

    desc 'Generate Defects4J example files'
    task generate: ['_data/examples', *D4J_EXAMPLE_DATA]

    rule(/_data\/examples\/defects4j_.*.yml$/) do |t|
      dir = "inputs/" + t.name.pathmap('%n').gsub('_', '/')
      before = Dir.glob("#{dir}/*.before")
      if before.count != 1
        raise "Multiple .before files in #{before.first.pathmap('%d')}"
      end

      before = before.first

      after = before.sub(/\.before$/, '.after')

      print_example_yml(t.name, :java, before, after)
    end
  end

  namespace :quixbugs do
    QB_JAVA_PROGRAMS = FileList['inputs/quixbugs/java_programs/*.java']
    QB_PYTHON_PROGRAMS = FileList['inputs/quixbugs/python_programs/*.py'].exclude('**/*_test.py')
    QB_EXAMPLE_DATA = \
      QB_JAVA_PROGRAMS.pathmap('_data/examples/quixbugs_java_%n.yml') \
      + QB_PYTHON_PROGRAMS.pathmap('_data/examples/quixbugs_python_%n.yml')

    task generate: ['_data/examples', *QB_EXAMPLE_DATA]

    rule(/_data\/examples\/quixbugs_.*.yml/) do |t|
      n = t.name.pathmap('%n').delete_prefix('quixbugs_')
      lang = n.split('_').first
      n = n.delete_prefix(lang + '_')
      ext = lang == 'python' ? 'py' : 'java'
      before = "inputs/quixbugs/#{lang}_programs/#{n}.#{ext}"
      after = "inputs/quixbugs/correct_#{lang}_programs/#{n}.#{ext}"

      if !File.exist?(after)
        puts "No correct file #{after}"
        next
      end

      print_example_yml(t.name, lang, before, after)
    end
  end
end

namespace :construct_usages do
  directory '_data/construct_usages'
  CLEAN.include('_data/construct_usages')

  def visit_tree_db(example, version, db, node)
    type = node[:type]
    fields = {}
    node[:fields].each do |k, v|
      fields[k] = [] unless fields.key?(k)
      fields[k] << (v.is_a?(String) ? 'String' : v[:type])
    end

    children = node[:children].map { |x| x[:type] }

    db[type] = [] unless db.key?(type)
    db[type] << { example:, version:, fields:, children: }
    db[type].uniq! { |val| [val[:fields], val[:children]] }

    node[:fields].each do |k, v|
      visit_tree_db(example, version, db, v) unless v.is_a?(String)
    end
    node[:children].each do |child|
      visit_tree_db(example, version, db, child)
    end
  end

  task generate: ['_data/construct_usages'] do
    db = {}
    files = Dir.glob('_data/examples/*.yml') do |filename|
      puts "Parsing #{filename}"
      example = YAML.safe_load_file(filename, symbolize_names: true)

      example_name = filename.pathmap('%n')
      visit_tree_db(example_name, 'before', db, example[:before_tree])
      visit_tree_db(example_name, 'after', db, example[:after_tree])
    end

    db.each do |k, v|
      File.write("_data/construct_usages/#{k}.yml", v.to_yaml(stringify_names: true))
    end
  end
end

namespace :grammars do
  desc 'Compile all tree-sitter grammars'
  task all: [:translation, :java, :python]

  desc 'Compile the translation grammar'
  task :translation do
    `cd tree-sitter-parsers/bugfix-translation && tree-sitter generate && make all`
  end

  desc 'Compile the java grammar'
  task :java do
    `cd tree-sitter-parsers/tree-sitter-java && tree-sitter generate && make all`
  end

  desc 'Compile the python grammar'
  task :python do
    `cd tree-sitter-parsers/tree-sitter-python && tree-sitter generate && make all`
  end
end

namespace :translate do
  namespace :java do
    desc 'Print the translation JSON for the given Java file'
    task :json, [:name] do |t, args|
      begin
        puts Translator.new.translate(:java, args[:name]).to_json
      rescue Translator::TranslationError => e
        STDERR.puts "SKIP TranslationError #{e}"
      end
    end
  end

  namespace :python do
    desc 'Print the translation JSON for the given Python file'
    task :json, [:name] do |t, args|
      begin
        puts Translator.new.translate(:python, args[:name]).to_json
      rescue Translator::TranslationError => e
        STDERR.puts "SKIP TranslationError #{e}"
      end
    end
  end

end
