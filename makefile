# Makefile for obrw
# run make obrw

CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -pedantic

obrw: obrw_main.h obrw_main.c obrw_chk_externals.h obrw_chk_externals.c obrw_config.h obrw_config.c obrw_globals.h obrw_globals.c obrw_utils.h obrw_utils.c obrw_string.h obrw_string.c obrw_wallpaper_opt.h obrw_wallpaper_opt.c
		$(CC) $(CFLAGS) -o obrw obrw_main.c

debug: obrw_main.h obrw_main.c obrw_chk_externals.c obrw_config.c obrw_globals.h obrw_globals.c obrw_utils.c obrw_string.c obrw_wallpaper_opt.c
		$(CC) $(CFLAGS) -g -o obrw obrw_main.c

val: obrw_main.c obrw_chk_externals.c obrw_config.c obrw_globals.h obrw_globals.c obrw_utils.c obrw_string.c obrw_wallpaper_opt.c
		$(CC) $(CFLAGS) -g -o obrw obrw_main.c
		valgrind -v --tool=memcheck --leak-check=full --show-reachable=yes --track-origins=yes --gen-suppressions=all ./obrw

clean:
	rm obrw
