#include <stdio.h>
#include "bits.h"

static int failures = 0;

#define CHECK(cond, msg)                                  \
    do {                                                  \
        if (cond) { printf("PASS: %s\n", msg); }          \
        else      { printf("FAIL: %s\n", msg); failures++; } \
    } while (0)

int main(void) {
    CHECK(set_bit(0x00, 3) == 0x08, "set_bit sets bit 3");
    CHECK(set_bit(0x08, 3) == 0x08, "set_bit on an already-set bit changes nothing");
    CHECK(clear_bit(0xFF, 0) == 0xFE, "clear_bit clears bit 0");
    CHECK(toggle_bit(0x01, 0) == 0x00, "toggle_bit turns a 1 into 0");
    CHECK(toggle_bit(0x00, 7) == 0x80, "toggle_bit turns a 0 into 1");
    CHECK(is_bit_set(0x10, 4), "is_bit_set finds bit 4");
    CHECK(!is_bit_set(0x10, 3), "is_bit_set reports a clear bit");
    CHECK(count_set_bits(0) == 0, "count_set_bits of 0 is 0");
    CHECK(count_set_bits(0xFF) == 8, "count_set_bits of 0xFF is 8");
    CHECK(count_set_bits(0xFFFFFFFFu) == 32, "count_set_bits of all ones is 32");

    printf("\n%d failure(s)\n", failures);
    return failures == 0 ? 0 : 1;
}
