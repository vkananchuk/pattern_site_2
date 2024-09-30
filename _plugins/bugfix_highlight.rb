# frozen_string_literal: true

require_relative '../lib/bugfix'

module Jekyll
  module BugfixHighlight
    def bugfix_highlight(text)
      inner = bugfix_highlight_inner(Bugfix.parse(text), 0)
      <<~HTML
        <figure class="highlight">
          <pre><code>#{inner}</code></pre>
        </figure>
      HTML
    end

    def bugfix_highlight_inner(ast, indent)
      result = ''
      return result unless ast

      if ast[:type]
        type_page = find_in_collection(ast[:type].to_s, 'constructs')
        type_page ||= find_in_collection(ast[:type].to_s, 'kinds')
        if type_page
          result += "(<a class=\"n nc\" href=\"#{absolute_url(type_page.url)}\">#{ast[:type]}</a>"
        else
          name_class = ast[:type].to_s.start_with?('@') ? 'nv' : 'nc'
          result += "(<span class=\"n #{name_class}\">#{ast[:type]}</span>"
        end
        if ast[:splat]
          result += "\n" + ('  ' * indent)
          result += "<span class=\"o\">**</span><span class=\"nl\">#{ast[:splat]}</span>"
        end
      elsif ast[:splat]
        result += "(<span class=\"o\">**</span><span class=\"nl\">#{ast[:splat]}</span>"
      else
        result += ast[:name].to_s
      end

      if ast[:children]
        ast[:children].each do |child|
          result += "\n" + '  ' * (indent + 1)
          if child[:field]
            result += "<span class=\"nv\">#{child[:field]}:</span> "
          end
          result += bugfix_highlight_inner(child[:node], indent + 1) + ' ' if child[:node]

          if child[:quantifier]
            quantifiers = {
              optional: '?',
              star: '*',
              plus: '+'
            }
            result += quantifiers[child[:quantifier]]
          end

          if child[:name]
            result += "<span class=\"nl\">#{child[:name]}</span>"
          end
        end
      end
      result += ')' if result.start_with?('(')

      result
    end
  end
end

Liquid::Template.register_filter(Jekyll::BugfixHighlight)
