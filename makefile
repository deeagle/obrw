# Makefile for obrw
# run make obrw

CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -pedantic

SRC = src/*
TARGET_DIR = bin
NAME = obrw
MAIN_C = src/obrw_main.c

# the compile 

all: obrw

obrw: $(SRC)
		$(CC) $(CFLAGS) -o $(TARGET_DIR)/$(NAME) $(MAIN_C)

debug: $(SRC)
		$(CC) $(CFLAGS) -g -o $(TARGET_DIR)/$(NAME) $(MAIN_C)

val: $(SRC)
		$(CC) $(CFLAGS) -g -o $(TARGET_DIR)/$(NAME) $(MAIN_C)
		valgrind -v --tool=memcheck --leak-check=full --show-reachable=yes --track-origins=yes --gen-suppressions=all ./$(TARGET_DIR)/$(NAME)

clean:
	rm $(TARGET_DIR)/$(NAME)
