#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 21
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 14
#define ALIAS_COUNT 0
#define TOKEN_COUNT 8
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 3

enum ts_symbol_identifiers {
  anon_sym_LPAREN = 1,
  anon_sym_RPAREN = 2,
  anon_sym_COLON = 3,
  anon_sym_STAR = 4,
  sym_id = 5,
  anon_sym_AT = 6,
  anon_sym_BANG = 7,
  sym_node = 8,
  sym_field = 9,
  sym_splat = 10,
  sym_variable = 11,
  sym_variable_text = 12,
  aux_sym_node_repeat1 = 13,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_STAR] = "*",
  [sym_id] = "id",
  [anon_sym_AT] = "@",
  [anon_sym_BANG] = "!",
  [sym_node] = "node",
  [sym_field] = "field",
  [sym_splat] = "splat",
  [sym_variable] = "variable",
  [sym_variable_text] = "variable_text",
  [aux_sym_node_repeat1] = "node_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_STAR] = anon_sym_STAR,
  [sym_id] = sym_id,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_BANG] = anon_sym_BANG,
  [sym_node] = sym_node,
  [sym_field] = sym_field,
  [sym_splat] = sym_splat,
  [sym_variable] = sym_variable,
  [sym_variable_text] = sym_variable_text,
  [aux_sym_node_repeat1] = aux_sym_node_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [sym_id] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [sym_node] = {
    .visible = true,
    .named = true,
  },
  [sym_field] = {
    .visible = true,
    .named = true,
  },
  [sym_splat] = {
    .visible = true,
    .named = true,
  },
  [sym_variable] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_text] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_node_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_name = 1,
  field_type = 2,
  field_value = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_type, 1},
  [1] =
    {field_name, 0},
    {field_value, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(1);
      if (lookahead == '!') ADVANCE(8);
      if (lookahead == '(') ADVANCE(2);
      if (lookahead == ')') ADVANCE(3);
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == ':') ADVANCE(4);
      if (lookahead == '@') ADVANCE(7);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(6);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_id);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(6);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [sym_id] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
  },
  [1] = {
    [sym_node] = STATE(20),
    [anon_sym_LPAREN] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(5), 1,
      anon_sym_RPAREN,
    ACTIONS(7), 1,
      anon_sym_STAR,
    ACTIONS(9), 1,
      sym_id,
    STATE(17), 1,
      sym_splat,
    STATE(3), 2,
      sym_field,
      aux_sym_node_repeat1,
  [17] = 5,
    ACTIONS(7), 1,
      anon_sym_STAR,
    ACTIONS(9), 1,
      sym_id,
    ACTIONS(11), 1,
      anon_sym_RPAREN,
    STATE(13), 1,
      sym_splat,
    STATE(5), 2,
      sym_field,
      aux_sym_node_repeat1,
  [34] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 1,
      anon_sym_AT,
    ACTIONS(15), 1,
      anon_sym_BANG,
    STATE(11), 3,
      sym_node,
      sym_variable,
      sym_variable_text,
  [49] = 3,
    ACTIONS(19), 1,
      sym_id,
    ACTIONS(17), 2,
      anon_sym_RPAREN,
      anon_sym_STAR,
    STATE(5), 2,
      sym_field,
      aux_sym_node_repeat1,
  [61] = 1,
    ACTIONS(22), 4,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_STAR,
      sym_id,
  [68] = 1,
    ACTIONS(24), 4,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_STAR,
      sym_id,
  [75] = 1,
    ACTIONS(26), 4,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_STAR,
      sym_id,
  [82] = 1,
    ACTIONS(28), 3,
      anon_sym_RPAREN,
      anon_sym_STAR,
      sym_id,
  [88] = 1,
    ACTIONS(30), 3,
      anon_sym_RPAREN,
      anon_sym_STAR,
      sym_id,
  [94] = 1,
    ACTIONS(32), 3,
      anon_sym_RPAREN,
      anon_sym_STAR,
      sym_id,
  [100] = 1,
    ACTIONS(34), 1,
      anon_sym_RPAREN,
  [104] = 1,
    ACTIONS(36), 1,
      anon_sym_RPAREN,
  [108] = 1,
    ACTIONS(38), 1,
      sym_id,
  [112] = 1,
    ACTIONS(40), 1,
      sym_id,
  [116] = 1,
    ACTIONS(42), 1,
      sym_id,
  [120] = 1,
    ACTIONS(11), 1,
      anon_sym_RPAREN,
  [124] = 1,
    ACTIONS(44), 1,
      anon_sym_COLON,
  [128] = 1,
    ACTIONS(46), 1,
      sym_id,
  [132] = 1,
    ACTIONS(48), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 17,
  [SMALL_STATE(4)] = 34,
  [SMALL_STATE(5)] = 49,
  [SMALL_STATE(6)] = 61,
  [SMALL_STATE(7)] = 68,
  [SMALL_STATE(8)] = 75,
  [SMALL_STATE(9)] = 82,
  [SMALL_STATE(10)] = 88,
  [SMALL_STATE(11)] = 94,
  [SMALL_STATE(12)] = 100,
  [SMALL_STATE(13)] = 104,
  [SMALL_STATE(14)] = 108,
  [SMALL_STATE(15)] = 112,
  [SMALL_STATE(16)] = 116,
  [SMALL_STATE(17)] = 120,
  [SMALL_STATE(18)] = 124,
  [SMALL_STATE(19)] = 128,
  [SMALL_STATE(20)] = 132,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_node_repeat1, 2, 0, 0),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_node_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 4, 0, 1),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3, 0, 1),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 5, 0, 1),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_text, 2, 0, 0),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable, 2, 0, 0),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 3, 0, 2),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_splat, 2, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [48] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_bugfix_translation(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
