# frozen_string_literal: true

class Sexp
  def self.parse(s)
    make_structure(
      s.gsub('(', ' ( ').gsub(')', ' ) ').split(' '),
      0
    ).first.first
  end

  def self.make_structure(tokens, i)
    result = []

    while i < tokens.size
      if tokens[i] == '('
        sub, i = make_structure(tokens, i + 1)
        result << (sub.empty? ? nil : sub)
      elsif tokens[i] == ')'
        return [result, i]
      else
        result << tokens[i]
      end
      i += 1
    end

    return [result, i]
  end
end
