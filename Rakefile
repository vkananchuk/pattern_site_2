require "minitest/test_task"
require 'yaml'
require 'rake/clean'
require 'tempfile'
require 'open3'

require_relative './lib/translator.rb'

Minitest::TestTask.create

task :default => :test

namespace :examples do
  directory '_data/examples'
  CLEAN.include('_data/examples')

  task all: ['defects4j:generate', 'quixbugs:generate']

  def print_example_yml(name, language, before, after)
    text_diff = `diff -u -Lbefore -Lafter #{before} #{after}`

    tree_diff = nil
    Tempfile.create do |xml_before|
      Tempfile.create do |xml_after|
        out, err, status = Open3.capture3("bundle exec rake translate:#{language}[#{before}] > #{xml_before.path}")
        if err.include?("TranslationError")
          puts "Skipping: #{err}"
          next
        end
        unless status.success?
          puts "ERROR translating #{before}"
          puts "STDOUT:"
          puts out
          puts "STDERR:"
          puts err
          raise "Error"
        end

        out, err, status = Open3.capture3("bundle exec rake translate:#{language}[#{after}] > #{xml_after.path}")
        if err.include?("TranslationError")
          puts "Skipping: #{err}"
          next
        end
        unless status.success?
          raise "ERROR translating #{after}"
          puts "STDOUT:"
          puts out
          puts "STDERR:"
          puts err
          raise "Error"
        end

        tree_diff = `gumtree cluster -g xml #{xml_before.path} #{xml_after.path}`
      end
    end

    return unless tree_diff

    yaml = {
      language: language.to_s,
      text_diff:,
      tree_diff:
    }

    File.write(name, yaml.to_yaml(stringify_names: true))
  end

  namespace :defects4j do
    D4J_EXAMPLE_DIRS = FileList['inputs/defects4j/**/*.java.after']
    D4J_EXAMPLE_DATA = D4J_EXAMPLE_DIRS.pathmap('%-3d').gsub('/', '_').map { |s| "_data/examples/#{s}.yml" }

    task generate: ['_data/examples', *D4J_EXAMPLE_DATA]

    rule(/_data\/examples\/defects4j_.*.yml$/) do |t|
      dir = "inputs/" + t.name.pathmap('%n').gsub('_', '/')
      before = Dir.glob("#{dir}/*.before")
      if before.count != 1
        raise "Multiple .before files in #{before.first.pathmap('%d')}"
      end

      before = before.first

      after = before.sub(/\.before$/, '.after')

      print_example_yml(t.name, :java, before, after)
    end
  end

  namespace :quixbugs do
    QB_JAVA_PROGRAMS = FileList['inputs/quixbugs/java_programs/*.java']
    QB_PYTHON_PROGRAMS = FileList['inputs/quixbugs/python_programs/*.py'].exclude('**/*_test.py')
    QB_EXAMPLE_DATA = \
      QB_JAVA_PROGRAMS.pathmap('_data/examples/quixbugs_java_%n.yml') \
      + QB_PYTHON_PROGRAMS.pathmap('_data/examples/quixbugs_python_%n.yml')

    task generate: ['_data/examples', *QB_EXAMPLE_DATA]

    rule(/_data\/examples\/quixbugs_.*.yml/) do |t|
      n = t.name.pathmap('%n').delete_prefix('quixbugs_')
      lang = n.split('_').first
      n = n.delete_prefix(lang + '_')
      ext = lang == 'python' ? 'py' : 'java'
      before = "inputs/quixbugs/#{lang}_programs/#{n}.#{ext}"
      after = "inputs/quixbugs/correct_#{lang}_programs/#{n}.#{ext}"

      if !File.exist?(after)
        puts "No correct file #{after}"
        next
      end

      print_example_yml(t.name, lang, before, after)
    end
  end
end

namespace :grammars do
  desc 'Compile all tree-sitter grammars'
  task all: [:translation, :java, :python]

  desc 'Compile the translation grammar'
  task :translation do
    `cd tree-sitter-parsers/bugfix-translation && tree-sitter generate && make all`
  end

  desc 'Compile the java grammar'
  task :java do
    `cd tree-sitter-parsers/tree-sitter-java && tree-sitter generate && make all`
  end

  desc 'Compile the python grammar'
  task :python do
    `cd tree-sitter-parsers/tree-sitter-python && tree-sitter generate && make all`
  end
end

namespace :translate do
  desc 'Print the Gumtree XML for the given Java file'
  task :java, [:name] do |t, args|
    begin
      puts Translator.new.translate(:java, args[:name]).to_xml
    rescue Translator::TranslationError => e
      STDERR.puts "SKIP TranslationError #{e}"
    end
  end

  desc 'Print the Gumtree XML for given Python file'
  task :python, [:name] do |t, args|
    begin
      puts Translator.new.translate(:python, args[:name]).to_xml
    rescue Translator::TranslationError => e
      STDERR.puts "SKIP TranslationError #{e}"
    end
  end
end
