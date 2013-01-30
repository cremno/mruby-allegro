MRuby::Gem::Specification.new('mruby-allegro') do |spec|
  spec.license = 'MIT'
  spec.authors = 'cremno'
  spec.mruby.linker.libraries << 'allegro-monolith'
end
