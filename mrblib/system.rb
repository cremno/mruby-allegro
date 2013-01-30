def al_init
  Al.init
end

def al_uninstall_system
  Al.uninstall
end

def al_is_system_installed
  Al.installed?
end

def al_get_allegro_version
  h = Al.version
  (h[:major] << 24) | (h[:minor] << 16) | (h[:revision] << 8) | h[:release]
end

def al_set_exe_name(s)
  Al.exe_name = s
end

def al_set_app_name(s)
  Al.app_name = s
end

def al_set_org_name
  Al.org_name = s
end

def al_get_app_name
  Al.app_name
end

def al_get_org_name
  Al.org_name
end
