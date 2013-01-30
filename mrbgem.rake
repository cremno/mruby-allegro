MRuby::Gem::Specification.new('mruby-allegro') do |spec|
  spec.license = 'MIT'
  spec.authors = 'cremno'
  spec.mruby.cc.defines << 'INIT_AT_START'
  # for the time being
  spec.mruby.linker.libraries << 'allegro-5.0.8-monolith-md-debug'
end
