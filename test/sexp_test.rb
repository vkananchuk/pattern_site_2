# frozen_string_literal: true

require 'lib/sexp'

class SexpTest < Minitest::Test
  def test_normal_example
    assert_equal ['a', 'b', ['c', 'd', ['e'], 'f']],
      Sexp.parse('(a b (c d (e) f))')
  end

  def test_empty_string
    assert_nil Sexp.parse('')
  end

  def test_empty_sexp
    assert_nil Sexp.parse('()')
  end

  def test_sexp_with_nil
    assert_equal [nil], Sexp.parse('(())')
  end
end
