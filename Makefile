# Recipe lines start with ">" instead of a TAB, so copy-paste can't break them
.RECIPEPREFIX = >

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c11 -Isrc
SRC     = src/ring_buffer.c
TEST    = tests/test_ring_buffer.c
BIN     = build/test_ring_buffer

.PHONY: all test clean

all: $(BIN)

$(BIN): $(SRC) $(TEST) src/ring_buffer.h
> mkdir -p build
> $(CC) $(CFLAGS) $(SRC) $(TEST) -o $(BIN)

test: $(BIN)
> ./$(BIN)

clean:
> rm -rf build
