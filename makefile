# Makefile for obrw
# run make obrw

CC = gcc
C_LANG_STD = c99
CFLAGS = -std=$(C_LANG_STD) -Wall -Wextra -pedantic
LDFLAGS =  # Add linker flags here if needed

SRC = $(wildcard src/*.c)
TEST_SRC = $(wildcard tests/*.c)
TEST_CLASS_NAME = test-all
TARGET_DIR = bin
NAME = obrw
MAIN_C = src/obrw_main.c
MAIN_TESTS = tests/obrw_tests.c
DOCS_DIR = doc
DOCS_APP = /usr/bin/doxygen
BIN_CPPCHECK = $(shell which cppcheck 2>/dev/null)

# the compile 

all: test run-tests obrw

obrw: $(SRC)
	@mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $(TARGET_DIR)/$(NAME) $(MAIN_C)

debug: $(SRC)
	@mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -g -o $(TARGET_DIR)/$(NAME) $(MAIN_C)

# Valgrind memory check
val: debug
	valgrind -v --tool=memcheck --leak-check=full --show-reachable=yes --track-origins=yes --gen-suppressions=all ./$(TARGET_DIR)/$(NAME)

# Run CI script
ci:
	bash run-ci.sh

# Run cppcheck with standard checks
cppcheck:
	@if [ -z "$(BIN_CPPCHECK)" ]; then \
		echo "ERROR: cppcheck not found. Install it via package manager."; \
		exit 1; \
	fi
	$(BIN_CPPCHECK) --std=$(C_LANG_STD) --language=c $(SRC) $(TEST_SRC)

# Run cppcheck with all checks enabled
cppcheck-all:
	@if [ -z "$(BIN_CPPCHECK)" ]; then \
		echo "ERROR: cppcheck not found. Install it via package manager."; \
		exit 1; \
	fi
	$(BIN_CPPCHECK) --std=$(C_LANG_STD) --language=c --enable=all $(SRC) $(TEST_SRC)

# Compile and run tests
test: $(SRC) $(TEST_SRC)
	@mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $(TARGET_DIR)/test-all $(MAIN_TESTS)
	$(BIN_CPPCHECK) --std=$(C_LANG_STD) --language=c --error-exitcode=1 $(SRC) $(TEST_SRC)

test-ndebug: $(SRC) $(TEST_SRC)
	@mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -DNDEBUG -o $(TARGET_DIR)/test-all $(MAIN_TESTS)

# Run compiled tests
run-tests:
	@./$(TARGET_DIR)/test-all

# Generate documentation
docs:
	@test -x $(DOCS_APP) || { echo "ERROR: Doxygen not found."; exit 1; }
	@mkdir -p $(DOCS_DIR)
	$(DOCS_APP)

# Cleanup build artifacts
clean:
	rm -f $(TARGET_DIR)/$(NAME) $(TARGET_DIR)/test-all
	rm -rf $(DOCS_DIR)

# Cleanup documentation only
clean-docs:
	rm -rf $(DOCS_DIR)

# Declare targets as PHONY
.PHONY: all obrw debug val ci cppcheck cppcheck-all test test-ndebug run-tests docs clean clean-docs
