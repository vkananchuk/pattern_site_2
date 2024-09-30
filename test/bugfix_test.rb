# frozen_string_literal: true

require 'lib/bugfix'

class BugfixTest < Minitest::Test
  def test_empty
    assert_nil Bugfix.parse('')
  end

  def test_normal_example
    assert_equal(
      {
        type: :top,
        children: [
          {
            field: :a,
            name: :@a,
            node: {
              type: :aa
            }
          }
        ]
      },
      Bugfix.parse('(top a: (aa) @a)')
    )
  end

  def test_quantifiers
    assert_equal(
      {
        type: :top,
        children: [
          { node: { type: :a }, quantifier: :optional },
          { node: { type: :b }, quantifier: :star },
          { node: { type: :c }, quantifier: :plus }
        ]
      },
      Bugfix.parse('(top (a)? (b)* (c)+)')
    )
  end

  def test_splat_first
    assert_equal(
      {
        splat: :@a
      },
      Bugfix.parse('(**@a)')
    )
  end

  def test_splat_second
    assert_equal(
      {
        type: :t,
        splat: :@x
      },
      Bugfix.parse('(t **@x)')
    )
  end
end
