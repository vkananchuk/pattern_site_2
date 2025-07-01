/**
 * @file Pattern language for Bugfix translation elements
 * @author -
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "bugfix_translation",

  rules: {
    node: $ => seq(
      '(',
      field('type', $.id),
      repeat($.field),
      optional($.splat),
      ')'
    ),

    field: $ => seq(
      field('name', $.id),
      ':',
      field('value', choice(
        $.node,
        $.variable,
        $.variable_text
      ))
    ),

    splat: $ => seq(
      '*',
      $.id
    ),

    id: $ => /\w+/,
    variable: $ => seq(
      '@',
      $.id
    ),
    variable_text: $ => seq(
      '!',
      $.id
    )
  }
});
