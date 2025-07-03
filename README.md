# Bugfix

## Installation
Clone this repository

``` sh
git clone # <REPO>
```

Install `tree-sitter` program.

Install Gumtree https://github.com/GumTreeDiff/gumtree for tree-based diffing.

Java and Python tree-sitter grammars are included as submodules in this repo.
Init and checkout sumodules:

``` sh
git submodule init
git submodule update
```

Compile Bugfix Translation grammar and language grammars:

``` sh
bundle exec rake grammar:all
```

## Running

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
