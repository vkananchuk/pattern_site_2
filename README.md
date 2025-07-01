Install Gumtree https://github.com/GumTreeDiff/gumtree for tree-based diffing.

Install `tree-sitter` and the grammars `tree-sitter-java` and `tree-sitter-python`.

Compile `bugfix-translation` grammar using

``` sh
bundle exec rake translate:compile
```

Generate the *examples* data using

``` sh
bundle exec rake examples:all
```

To start, run in docker console:
```sh
bundle instal
bundle exec jekyll serve
```

And open http://localhost:4000
