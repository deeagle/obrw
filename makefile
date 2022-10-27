# Makefile for obrw
# run make obrw

CC = gcc
C_LANG_STD = c99

CFLAGS = -std=$(C_LANG_STD) -Wall -Wextra -pedantic

SRC = src/*
TEST_FILE_DIR = tests/*
TEST_CLASS_NAME = test-all
TARGET_DIR = bin
NAME = obrw
MAIN_C = src/obrw_main.c
MAIN_TESTS = tests/obrw_tests.c
DOCS_DIR = doc
DOCS_APP = /usr/bin/doxygen
BIN_CPPCHECK = /usr/bin/cppcheck

# the compile 

all: test run-tests obrw

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

cppcheck: $(SRC) $(TEST_FILE_DIR)
	@if [ ! -f "$(BIN_CPPCHECK)" ]; then \
		echo "ERROR: $(BIN_CPPCHECK) not found."; \
		echo "       you can install it via package manager."; \
		exit 1; \
	else \
		$(BIN_CPPCHECK) --std=$(C_LANG_STD) --language=c $(SRC) $(TEST_FILE_DIR); \
	fi

test: $(SRC) $(TEST_FILE_DIR)
		@if [ ! -d "./$(TARGET_DIR)" ]; then \
			mkdir $(TARGET_DIR); \
		fi
		$(CC) -o $(TARGET_DIR)/$(TEST_CLASS_NAME) $(MAIN_TESTS)
		$(BIN_CPPCHECK) --std=$(C_LANG_STD) --language=c --error-exitcode=1 $(SRC) $(TEST_FILE_DIR)

test-ndebug: $(SRC) $(TEST_FILE_DIR)
		if [ ! -d "./$(TARGET_DIR)" ]; then \
			mkdir $(TARGET_DIR); \
		fi
		$(CC) -DNDEBUG -o $(TARGET_DIR)/$(TEST_CLASS_NAME) $(MAIN_TESTS)

run-tests:
	./$(TARGET_DIR)/$(TEST_CLASS_NAME)

docs:
	test -x $(DOCS_APP)
	if [ ! -d "./$(DOCS_DIR)" ]; then \
	mkdir $(DOCS_DIR); \
	fi
	$(DOCS_APP)

clean:
	rm -f $(TARGET_DIR)/$(NAME)
	rm -f $(TARGET_DIR)/$(TEST_CLASS_NAME)
	rm -Rf $(DOCS_DIR)

clean-docs:
	rm -Rf $(DOCS_DIR)
