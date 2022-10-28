/**
 * << OBRW - OpenBoxRandomWallpaper >> -- obrw_chk_externals.h
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_factory.c
 */
#include "obrw_factory.h"

struct wallpaper obrwFactory_getWallpaperItem() {
    struct wallpaper usedWallpaper;
    usedWallpaper.arrayIndex = -1;
    strcpy(usedWallpaper.name, "");

    return usedWallpaper;
}
