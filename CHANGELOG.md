# Changelog

## [0.2.1] - 2024-07-03

### Fixed

- Add untracked files (`src/ports/*`) to the repository ([`5207ef4`](https://github.com/lapkowski/result/commits/5207ef4)) ([**@lapkowski**](https://github.com/lapkowski))

## [0.2.0] - 2024-07-02

_This release does not build due to missing files ([`5207ef4`](https://github.com/lapkowski/result/commits/5207ef4))._

### Changed

- **BREAKING:** Make RESULT_DEFINE require the type declaration with RESULT_DECLARE ([`5d8affe`](https://github.com/lapkowski/result/commit/5d8affe)) ([**@lapkowski**](https://github.com/lapkowski))
- **BREAKING:** move the libc error definitions (`ports/errors.h`) to `ports/libc/errors.h` ([`d234e04`](https://github.com/lapkowski/result/commit/d234e04), [`7f93c78`](https://github.com/lapkowski/result/commit/7f93c78)) ([**@lapkowski**](https://github.com/lapkowski))
- Move the error definitions, result type method definitions and panic function definitons from header files to source files ([`7fba5c4`](https://github.com/lapkowski/result/commit/7fba5c4), [`dba5fd1`](https://github.com/lapkowski/result/commit/dba5fd1), [`a42bf06`](https://github.com/lapkowski/result/commit/a42bf06), [`5b7e933`](https://github.com/lapkowski/result/commit/5b7e933), [`5b7e933`](https://github.com/lapkowski/result/commit/5b7e933)) ([**@lapkowski**](https://github.com/lapkowski))
- Rewrite the `CHANGELOG.md` to follow the [`Common Changelog`](https://common-changelog.org) style. ([`c0e7f4c`](https://github.com/lapkowski/result/commit/c0e7f4c), [`0b9befe`](https://github.com/lapkowski/result/commit/0b9befe), [`f3ca7a2`](https://github.com/lapkowski/result/commit/f3ca7a2)) ([**@lapkowski**](https://github.com/lapkowski))

### Added

- Add the `RESULT_DECLARE` and `ERROR_DEFINE` macros for declaring the types without compiling them into objects ([`5d8affe`](https://github.com/lapkowski/result/commit/5d8affe)) ([**@lapkowski**](https://github.com/lapkowski))
- Add the `RESULT_DEFINE_WITH_TYPE` to replace previous `RESULT_DEFINE` behavior (If you include a header with a `RESULT_DECLARE` macro, use `RESULT_DEFINE`). ([`5d8affe`](https://github.com/lapkowski/result/commit/5d8affe)) ([**@lapkowski**](https://github.com/lapkowski))
- Add compilation flags to `INSTALL.md` ([`cab2b8d`](https://github.com/lapkowski/result/commit/cab2b8d)) ([**@lapkowski**](https://github.com/lapkowski))

### Fixed

- Add the `error.h` include to `ports/libc/errors.h` ([`aa013ee`](https://github.com/lapkowski/result/commit/aa013ee)) ([**@lapkowski**](https://github.com/lapkowski))
- Fix the `ROADMAP.md` to follow the Markdown checkbox style ([`01d54fb`](https://github.com/lapkowski/result/commit/01d54fb)) ([**@lapkowski**](https://github.com/lapkowski))

## [0.1.3] - 2024-06-24

### Changed

- Change the documentation installation directory to `/usr/share/doc/result` ([`61da4c8`](https://github.com/lapkowski/result/commit/61da4c8)) ([**@lapkowski**](https://github.com/lapkowski))

### Fixed

- Fix some minor conversion errors in the documentation ([`35c6d40`](https://github.com/lapkowski/result/commit/35c6d40)) ([**@lapkowski**](https://github.com/lapkowski))

## [0.1.2] - 2024-06-24

### Fixed

- Include the version macros in the `result.h` header ([`00edbe1`](https://github.com/lapkowski/result/commits/00edbe1)) ([**@lapkowski**](https://github.com/lapkowski))

## [0.1.1] - 2024-06-22

### Removed

- Remove the `vcs_version.h` header ([`628dbab`](https://github.com/lapkowski/result/commit/628dbab)) ([**@lapkowski**](https://github.com/lapkowski))

### Fixed

- Fix the build system not passing the configure phase ([`628dbab`](https://github.com/lapkowski/result/commit/628dbab)) ([**@lapkowski**](https://github.com/lapkowski))

## [0.1.0] - 2024-06-17

_Initial Release_

[0.2.1]: https://github.com/lapkowski/result/releases/tag/v0.2.1
[0.2.0]: https://github.com/lapkowski/result/releases/tag/v0.2.0
[0.1.3]: https://github.com/lapkowski/result/releases/tag/v0.1.3
[0.1.2]: https://github.com/lapkowski/result/releases/tag/v0.1.2
[0.1.1]: https://github.com/lapkowski/result/releases/tag/v0.1.1
[0.1.0]: https://github.com/lapkowski/result/releases/tag/v0.1.0
