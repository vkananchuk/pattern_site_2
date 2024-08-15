# frozen_string_literal: true

module Jekyll
  class DataBasedPage < PageWithoutAFile
    def initialize(
      site,
      dir,
      key,
      value,
      front_matter:,
      output_ext:
    )
      super(site, site.source, dir, key + output_ext)

      @output_ext = output_ext

      self.data['data_key'] = key
      self.data['data_value'] = value
      self.data['title'] = key
      self.data.merge!(front_matter)
    end

    def output_ext
      @output_ext
    end
  end

  class DataBasedPageGenerator < Generator
    def generate(site)
      conf = site.config['data-based-pages']
      return unless conf

      cols = conf['data-collections']
      return unless cols

      cols.each do |col|
        path = col['path']
        front_matter = col['front-matter']
        output_ext = col.fetch('output-ext', '.html')

        data = site.data.dig(path)

        # Make hash from array with 1-based indices as keys
        data = Hash[(1...data.size).zip(data)] if data.is_a?(Array)

        data.each do |k, v|
          site.pages << DataBasedPage.new(
            site,
            col['dir'],
            k,
            v,
            front_matter:,
            output_ext:
          )
        end
      end
    end
  end
end
