//
// Created by deeagle on 5/26/20.
//

#include "obrw_configTest.h"

void
obrw_configTest_runAll()
{
    setWallpaperDir_setWallpaperDirectoryWithNull_expectedNullAsResult();
    setWallpaperDir_setWallpaperDirectoryWithTrainlingSlash_expectedWallpaperDirectoryAsStringResult();
    setWallpaperDir_setWallpaperDirectoryWithoutTrainlingSlash_expectedWallpaperDirectoryWithTrailingSlashAsStringResult();
}

void
setWallpaperDir_setWallpaperDirectoryWithNull_expectedNullAsResult()
{
    printf("%s - setWallpaperDir_setWallpaperDirectoryWithNull_expectedNullAsResult()\n", OBRW_CONFIGTEST_CLASS_NAME);

    const char *str = NULL;
    const char *result;

    result = obrwConfig_setWallpaperDir(str);
    assert(result == NULL);
}

void
setWallpaperDir_setWallpaperDirectoryWithTrainlingSlash_expectedWallpaperDirectoryAsStringResult()
{
    printf("%s - setWallpaperDir_setWallpaperDirectoryWithTrainlingSlash_expectedWallpaperDirectoryAsStringResult\n",
           OBRW_CONFIGTEST_CLASS_NAME);

    const char *str = "/home/user/.config/wallpaper-directory/1024x768/";
    const char *expected = "/home/user/.config/wallpaper-directory/1024x768/";
    const char *result;

    result = obrwConfig_setWallpaperDir(str);
    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}

void
setWallpaperDir_setWallpaperDirectoryWithoutTrainlingSlash_expectedWallpaperDirectoryWithTrailingSlashAsStringResult()
{
    printf("%s - setWallpaperDir_setWallpaperDirectoryWithoutTrainlingSlash_expectedWallpaperDirectoryWithTrailingSlash\n",
           OBRW_CONFIGTEST_CLASS_NAME);

    const char *str = "/home/user/.config/wallpaper-directory/1024x768";
    const char *expected = "/home/user/.config/wallpaper-directory/1024x768/";
    const char *result;

    result = obrwConfig_setWallpaperDir(str);

    assert(result != NULL);
    assert(0 == strcmp(expected, result));
}
