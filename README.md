# OBRW - OpenBoxRandomWallpaper

![Build status](https://github.com/deeagle/obrw/workflows/Build/badge.svg)

**OBRW** is a tool to set wallpapers randomly for the window manager **openbox**.
It's started as my '_first C-language-project_' and helped me to pass my exams.

> But why **C** and not another bash-script or maybe python?

Because **openbox** is in **C**.

ATM it's not really perfect, and I'm still not a C-programmer,
but the tool is working for years in my environments and I have some fun.

My most used commands are implemented via `make`.

## Tests and analysis

I test the code with:

- some own implemented unit-tests (atm no framework)
- dynamic/static code analysis frameworks:
  - [cppcheck](https://cppcheck.sourceforge.io/)
  - [valgrind](https://valgrind.org/)

## Externals

**OBRW** depends on:

- **feh** a fast and light `lmlib2`-based image viewer

## Example resources

- [Config file](resources/obrw.conf)
  Copy the file to your home-dir (spot the dot!) and adapt the wallpaper dir.
  You can use the following command `cp resources/obrw.conf ~/.obrw.conf`.

## Weblinks

- [CHANGELOG](CHANGELOG.md)

- A good choice to start with openbox is the project page or the debian-wiki:
  - [Openbox project](http://openbox.org/wiki/Main_Page)
  - [wiki.debian.org](https://wiki.debian.org/Openbox)
  - [feh](https://feh.finalrewind.org/)
