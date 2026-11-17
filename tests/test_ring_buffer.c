#include <stdio.h>
#include "ring_buffer.h"

static int failures = 0;

#define CHECK(cond, msg)                                  \
    do {                                                  \
        if (cond) { printf("PASS: %s\n", msg); }          \
        else      { printf("FAIL: %s\n", msg); failures++; } \
    } while (0)

int main(void) {
    ring_buffer_t rb;
    uint8_t value;

    rb_init(&rb);
    CHECK(rb_is_empty(&rb), "new buffer is empty");
    CHECK(!rb_pop(&rb, &value), "pop on empty buffer fails");

    for (uint8_t i = 0; i < RB_CAPACITY; i++) {
        rb_push(&rb, i);
    }
    CHECK(rb_is_full(&rb), "buffer is full after RB_CAPACITY pushes");
    CHECK(!rb_push(&rb, 99), "push on full buffer fails");

    CHECK(rb_pop(&rb, &value) && value == 0, "first pop returns first value (FIFO)");

    CHECK(rb_push(&rb, 42), "push succeeds after one pop (wrap-around)");
    for (int i = 0; i < RB_CAPACITY - 1; i++) {
        rb_pop(&rb, &value);
    }
    CHECK(rb_pop(&rb, &value) && value == 42, "wrapped value comes out last");
    CHECK(rb_is_empty(&rb), "buffer is empty after popping everything");

    printf("\n%d failure(s)\n", failures);
    return failures == 0 ? 0 : 1;
}
