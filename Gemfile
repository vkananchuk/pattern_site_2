source "https://rubygems.org"
# Hello! This is where you manage which Jekyll version is used to run.
# When you want to use a different version, change it below, save the
# file and run `bundle install`. Run Jekyll with `bundle exec`, like so:
#
#     bundle exec jekyll serve
#
# This will help ensure the proper Jekyll version is running.
# Happy Jekylling!
# This is the default theme for new Jekyll sites. You may change this to anything you like.
gem 'jekyll', '~> 4.4', '>= 4.4.1'
# If you have any plugins, put them here!
group :jekyll_plugins do
  gem 'jekyll-seo-tag', '~> 2.8'
  gem 'jekyll-remote-theme', '~> 0.4.3'
end

# Windows and JRuby does not include zoneinfo files, so bundle the tzinfo-data gem
# and associated library.
platforms :mingw, :x64_mingw, :mswin, :jruby do
  gem "tzinfo", ">= 1", "< 3"
  gem "tzinfo-data"
end

# Performance-booster for watching directories on Windows
gem "wdm", "~> 0.1.1", :platforms => [:mingw, :x64_mingw, :mswin]

# Lock `http_parser.rb` gem to `v0.6.x` on JRuby builds since newer versions of the gem
# do not have a Java counterpart.
gem "http_parser.rb", "~> 0.6.0", :platforms => [:jruby]

gem 'webrick', '~> 1.8', '>= 1.8.1'
gem 'minitest', '~> 5.25', '>= 5.25.1'

# gem 'ruby_tree_sitter', '~> 2.0'
gem 'ruby_tree_sitter', '~> 1.12'
# gem 'ruby_tree_sitter', path: '~/ruby-tree-sitter/'

gem 'nokogiri', '~> 1.18', '>= 1.18.8'
