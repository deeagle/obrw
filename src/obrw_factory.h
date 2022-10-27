
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
