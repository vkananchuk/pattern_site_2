package tree_sitter_bugfix_translation_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_bugfix_translation "github.com/tree-sitter/tree-sitter-bugfix_translation/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_bugfix_translation.Language())
	if language == nil {
		t.Errorf("Error loading Bugfix Translation grammar")
	}
}
