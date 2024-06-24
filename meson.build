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
  [
    'include/ports/errors.h',
    'include/ports/ports.h'
  ],
  subdir: 'result/ports'
)

install_man('man/result.3')

install_data(['CHANGELOG.md', 'LICENSE', 'README.md', 'ROADMAP.md'], install_dir: get_option('datadir') / 'doc')
install_data('docs/docs.md', install_dir: get_option('datadir') / 'doc/result')
