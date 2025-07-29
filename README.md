# Bugfix

## Installation
Clone this repository

``` sh
git clone # <REPO>
```

Install ruby dependencies

``` sh
bundle install
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

Generate the *examples* data using (hint: `-m` makes it run in parallel)

``` sh
bundle exec rake -m examples:all
```

Generate the construct usages data using

``` sh
bundle exec rake construct_usages:generate
```

To start the website run:
```sh
bundle exec jekyll serve
```

And open http://localhost:4000
