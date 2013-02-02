MRuby::Gem::Specification.new('mruby-allegro') do |spec|
  spec.license = 'MIT'
  spec.authors = 'cremno'
  spec.cc.defines << %w(INIT_AT_START ALLEGRO_STATICLINK)
  if ENV['OS'] == 'Windows_NT'
    spec.linker.libraries << %w(allegro-5.0.8-monolith-static-mt-debug freetype-2.4.8-static-mt-debug user32 gdi32 opengl32 glu32 winmm ole32 shell32 shlwapi gdiplus)
  else
    spec.cc.include_paths << ['/usr/local/include']
    spec.linker.library_paths << ['/usr/local/lib']
    spec.linker.libraries << ['allegro', 'allegro_primitives', 'allegro_image', 'allegro_font', 'allegro_ttf']
  end
  # uncomment this to enable global functions with the
  # same name and parameter(s) as their C equivalent
  #spec.rbfiles = Dir.glob("#{dir}/llapi/*.rb")
end
