# OBRW - OpenBoxRandomWallpaper

![Build status](https://github.com/deeagle/obrw/workflows/Build/badge.svg)

## Desc

**OBRW** is a tool to set wallpapers randomly for the window manager **openbox**.
It's started as my '_first C-language-project_' and helped me to pass my exams.

But why **C** and not another bash-script or maybe python?  
Because **openbox** is in **C**.

ATM it's not really perfect and I'm not a C-programmer,
but the tool is working for years in my environments.

## Externals

**OBRW** depends on:

- **feh** a fast and light lmlib2-based image viewer

## make

Supported options are:

- `make`
  - `test`
  - `run-tests`
  - `obrw`
- `obrw`
- `val`
  - checks valgrind
- `test`
  - Builds the executable `test-all`
- `run-tests`
  - Runs the executable `test-all`
- `docs`
- `clean`
- `clean-docs` 

## Weblinks

A good choice to start with openbox is the project page or the debian-wiki.

- [CHANGELOG](CHANGELOG.md)
- [Openbox project](http://openbox.org/wiki/Main_Page)
- [wiki.debian.org](https://wiki.debian.org/Openbox)
- [feh](https://feh.finalrewind.org/)
