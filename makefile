# Makefile for obrw
# run make obrw

CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -pedantic

SRC = src/*
TARGET_DIR = bin
NAME = obrw
MAIN_C = src/obrw_main.c
DOCS_DIR = doc
DOCS_APP = /usr/bin/doxygen

# the compile 

all: obrw

obrw: $(SRC)
		if [ ! -d "./$(TARGET_DIR)" ]; then \
			mkdir $(TARGET_DIR); \
		fi
		$(CC) $(CFLAGS) -o $(TARGET_DIR)/$(NAME) $(MAIN_C)

debug: $(SRC)
		$(CC) $(CFLAGS) -g -o $(TARGET_DIR)/$(NAME) $(MAIN_C)

val: $(SRC)
		$(CC) $(CFLAGS) -g -o $(TARGET_DIR)/$(NAME) $(MAIN_C)
		valgrind -v --tool=memcheck --leak-check=full --show-reachable=yes --track-origins=yes --gen-suppressions=all ./$(TARGET_DIR)/$(NAME)

docs:
	test -x $(DOCS_APP)
	if [ ! -d "./$(DOCS_DIR)" ]; then \
    	mkdir $(DOCS_DIR); \
    fi
	$(DOCS_APP)

clean:
	rm $(TARGET_DIR)/$(NAME)
	rm -Rf $(DOCS_DIR)
