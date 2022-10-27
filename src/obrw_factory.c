
#include "obrw_factory.h"

struct wallpaper obrwFactory_getWallpaperItem() {
    struct wallpaper usedWallpaper;
    usedWallpaper.arrayIndex = -1;
    strcpy(usedWallpaper.name, "");

    return usedWallpaper;
}
