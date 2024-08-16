# frozen_string_literal: true

module Jekyll
  class DataBasedPage < Document
    def initialize(
      site,
      dir,
      key,
      value,
      front_matter:,
      output_ext:,
      collection:
    )
      # super(site, site.source, dir, key + output_ext)
      super("#{key}#{output_ext}", site:, collection:)

      @output_ext = output_ext
      @collection = collection

      data['data_key'] = key
      data['data_value'] = value
      data['title'] = key
      data.merge!(front_matter)

      read_post_data
    end
  end

  class DataBasedCollection < Collection
    def add_page(p, key)
      mapping[key] = p
      docs << p
    end

    def get_page(key)
      mapping[key]
    end

    def mapping
      @mapping ||= {}
    end

    def write?
      true
    end
  end

  class KindsDataGenerator < Generator
    def generate(site)
      site.data['kinds'] = site.data['constructs']
        .flat_map { |k, v| v['kinds'] }
        .compact
        .to_h { |kind| [kind, {}] }
    end

    def <=>(other)
      if other.is_a?(DataBasePageGenerator)
        1
      else
        super
      end
    end

  end

  class DataBasedPageGenerator < Generator
    def generate(site)
      conf = site.config['data-based-pages']
      return unless conf

      cols = conf['data-collections']
      return unless cols

      cols.each do |col_key, col|
        collection = DataBasedCollection.new(site, col_key)
        site.collections[col_key] = collection

        path = col.fetch('path', col_key)
        dir = col.fetch('dir', col_key)
        front_matter = col['front-matter']
        output_ext = col.fetch('output-ext', '.html')

        data = site.data.dig(path)

        # Make hash from array with 1-based indices as keys
        data = Hash[(1...data.size).zip(data)] if data.is_a?(Array)

        data.each do |k, v|
          collection.add_page(
            DataBasedPage.new(
              site,
              dir,
              k,
              v,
              front_matter:,
              output_ext:,
              collection:
            ),
            k
          )
        end
      end
    end

    def <=>(other)
      if other.is_a?(KindsDataGenerator)
        -1
      else
        super
      end
    end
  end

  module CollectionPageFilter
    def find_in_collection(key, collection)
      @context.registers[:site].collections[collection].get_page(key)
    end

    def page_url(input)
      input&.url
    end

    def dig(input, path)
      res = input
      path.split('.').each do |k|
        res = res[k] if res
      end
      res
    end
  end
end

Liquid::Template.register_filter(Jekyll::CollectionPageFilter)
