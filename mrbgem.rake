MRuby::Gem::Specification.new('mruby-allegro') do |spec|
  spec.license = 'MIT'
  spec.authors = 'cremno'

  if ENV['OS'] == 'Windows_NT'
    spec.cc.defines << 'ALLEGRO_STATICLINK'
    spec.linker.libraries << 'allegro-5.0.8-monolith-static-mt'
    spec.linker.libraries << 'freetype-2.4.8-static-mt'
    spec.linker.libraries << %w(uuid gdiplus psapi shlwapi comdlg32 user32 ole32 gdi32 opengl32 glu32 shell32 winmm)
  else
    spec.cc.include_paths << '/usr/local/include'
    spec.linker.library_paths << '/usr/local/lib'
    spec.linker.libraries << %w(allegro allegro_primitives allegro_dialog allegro_image allegro_font allegro_ttf)
  end

  # uncomment this to enable global functions with the
  # same name and parameter(s) as their C equivalent
  #spec.rbfiles = Dir.glob("#{dir}/llapi/*.rb")

  # this initializes allegro and its addons when this gem is initialized
  spec.cc.defines << 'INIT_AT_START'
end
