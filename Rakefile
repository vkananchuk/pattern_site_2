require "minitest/test_task"
require 'yaml'
require 'rake/clean'

Minitest::TestTask.create

task :default => :test

namespace :examples do

  directory 'inputs'
  CLOBBER.include('inputs')

  directory '_data/examples'
  CLEAN.include('_data/examples')

  task all: ['defects4j:generate', 'quixbugs:generate']

  def print_example_yml(name, language, before, after)
    text_diff = `diff -u -Lbefore -Lafter #{before} #{after}`

    language = language.to_s

    tree_generator = language == 'java' ? 'java-treesitter-ng' : 'python-treesitter-ng'
    tree_diff = `gumtree cluster -g #{tree_generator} #{before} #{after}`

    yaml = {
      language: language,
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
        puts "SKIP: Multiple .before files #{before}"
        next
      end
      before = before.first

      after = before.sub(/\.before$/, '.after')

      print_example_yml(t.name, :java, before, after)
    end
  end

  namespace :quixbugs do
    CLOBBER.include('inputs/quixbugs')
    task download: 'inputs' do
      `git clone git@github.com:jkoppel/QuixBugs.git inputs/quixbugs`
    end


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

namespace :generate do


  task :examples do

  end
end
