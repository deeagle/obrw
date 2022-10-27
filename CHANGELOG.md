# CHANGELOG

All notable changes will be documented in this file.

<!-- markdownlint-disable MD013 MD024 -->

## UNRELEASED

### Fixed

- Reduced the scope of some variables.
- Removed multiple identical conditions.
- Make range checks better readable.

## 0.2.2 - 2022.10.27

### Fixed

- Version tag in cli.

## 0.2.1 - 2022.10.27

### Fixed

- Codestyle: remove useless else condition to prevent uninitialized value error by codecheck.

## 0.2.0 - 2020.05.26

### Features

- Added static code analysis tool [cppcheck](https://github.com/danmar/cppcheck).
- Added logging.
- Added some basic unit tests.
- Added version number via cli.

### Fixed

- Deadlock if only one wallpaper exists.
- Some buffer overflows.
- Reactive build on debian buster (10).

### Removed

- Docs from VCS (you can build them via `make docs`).

## 0.1.0 - 2014.08.14

- git init.

<!-- markdownlint-enable MD013 MD024 -->
