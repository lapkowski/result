project('result', 'c', version: '0.1.3')

revision = 3
major = 0
minor = 1
patch = 3

conf_data = configuration_data()
conf_data.set('VERSION', meson.project_version())
conf_data.set('REVISION', revision)
conf_data.set('MAJOR', major)
conf_data.set('MINOR', minor)
conf_data.set('PATCH', patch)

version_file = configure_file(input: 'include/version.h.in', output: 'version.h', configuration: conf_data)

install_headers(
  [
    'include/result.h',
    'include/error.h',
    'include/panic.h',
    version_file
  ],
  subdir: 'result'
)

install_headers(
  'include/ports/ports.h',
  subdir: 'result/ports'
)

install_headers(
  'include/ports/libc/errors.h',
  subdir: 'result/ports/libc'
)

library_sources = [ 'src/result.c', 'src/panic.c', 'src/ports/ports.c', 'src/ports/libc/errors.c' ]

pkg_config = import('pkgconfig')

if get_option('shared_library').enabled()

  sh_lib = shared_library('result', library_sources, version: meson.project_version(), soversion: major.to_string() + '.' + minor.to_string(), include_directories: include_directories('include'), install: true)
  pkg_config.generate(sh_lib)

endif

if get_option('static_library').enabled() or get_option('tests').enabled()

  st_lib = static_library('result', library_sources, include_directories: include_directories('include'), install: get_option('static_library').enabled())
  pkg_config.generate(st_lib)

endif

install_man('man/result.3')

install_data(['CHANGELOG.md', 'LICENSE', 'README.md', 'ROADMAP.md'], install_dir: get_option('datadir') / 'doc')
install_data('docs/docs.md', install_dir: get_option('datadir') / 'doc/result')

if get_option('tests').enabled()

endif
