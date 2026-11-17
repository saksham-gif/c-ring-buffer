# Recipe lines start with ">" instead of a TAB, so copy-paste can't break them
.RECIPEPREFIX = >

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror -std=c11 -Isrc
RB_BIN   = build/test_ring_buffer
BITS_BIN = build/test_bits

.PHONY: all test clean

all: $(RB_BIN) $(BITS_BIN)

$(RB_BIN): src/ring_buffer.c tests/test_ring_buffer.c src/ring_buffer.h
> mkdir -p build
> $(CC) $(CFLAGS) src/ring_buffer.c tests/test_ring_buffer.c -o $@

$(BITS_BIN): src/bits.c tests/test_bits.c src/bits.h
> mkdir -p build
> $(CC) $(CFLAGS) src/bits.c tests/test_bits.c -o $@

test: all
> ./$(RB_BIN)
> ./$(BITS_BIN)

clean:
> rm -rf build
