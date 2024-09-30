# frozen_string_literal: true

require_relative 'sexp'

class Bugfix
  def self.parse(s)
    make_node(Sexp.parse(s))
  end

  def self.make_node(sexp)
    return unless sexp

    node = {}
    i = 0
    if sexp.first.start_with?('**')
      node[:splat] = sexp.first.delete_prefix('**').to_sym
      i = 1
    else
      node[:type] = sexp.first.to_sym
      i = 1
      if i < sexp.size && sexp[i].is_a?(String) && sexp[i].start_with?('**')
        node[:splat] = sexp[i].delete_prefix('**').to_sym
        i = 2
      end
    end

    children = []

    while i < sexp.size
      child = {}

      if sexp[i].is_a?(String) && sexp[i].end_with?(':')
        child[:field] = sexp[i].delete_suffix(':').to_sym
        i += 1
      end

      if sexp[i].is_a?(Array)
        child[:node] = make_node(sexp[i])
        i += 1

        # Quantifiers appear only after ()
        if sexp[i] == '?'
          child[:quantifier] = :optional
          i += 1
        elsif sexp[i] == '*'
          child[:quantifier] = :star
          i += 1
        elsif sexp[i] == '+'
          child[:quantifier] = :plus
          i += 1
        end
      end

      if sexp[i].is_a?(String) && !sexp[i].end_with?(':')
        child[:name] = sexp[i].to_sym
        i += 1
      end

      children << child
    end

    if children.size > 0
      node[:children] = children
    end

    node
  end
end
