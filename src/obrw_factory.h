/**
 * << OBRW - OpenBoxRandomWallpaper >>
 *
 * URL: http://deeagle.de
 *
 * \author Martin Kock <code@deeagle.de>
 * \file obrw_factory.h
 *
 * \brief The file includes factory functions as centralized spot to create objects.
 */
#ifndef OBRW_FACTORY_H
#define OBRW_FACTORY_H

#include <string.h>

/**
 * Simple wallpaper item.
 */
struct wallpaper {
    /** array index for debug */
    int arrayIndex;
    /** name of the wallpaper */
    char name[1024];
};

/**
 * Returns an empty wallpaper item.
 *
 * @return An empty wallpaper item.
 */
struct wallpaper obrwFactory_getWallpaperItem(void);

#endif  // OBRW_FACTORY_H
