//
// Created by deeagle on 5/26/20.
//

#ifndef OBRW_OBRW_CONFIGTEST_H
#define OBRW_OBRW_CONFIGTEST_H

#include <assert.h>
#include <stdio.h>
#include "../src/obrw_config.h"

static const char* OBRW_CONFIGTEST_CLASS_NAME = "obrw_configTest\0";

void obrw_configTest_runAll();

void setWallpaperDir_setWallpaperDirectoryWithNull_expectedNullAsResult();
void setWallpaperDir_setWallpaperDirectoryWithTrainlingSlash_expectedWallpaperDirectoryAsStringResult();
void setWallpaperDir_setWallpaperDirectoryWithoutTrainlingSlash_expectedWallpaperDirectoryWithTrailingSlashAsStringResult();

#endif //OBRW_OBRW_CONFIGTEST_H
