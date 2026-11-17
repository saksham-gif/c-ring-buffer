#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RB_CAPACITY 8
_Static_assert((RB_CAPACITY & (RB_CAPACITY - 1)) == 0, "RB_CAPACITY must be a power of two");

typedef struct {
    uint8_t data[RB_CAPACITY];
    size_t head;   /* next write index */
    size_t tail;   /* next read index  */
    size_t count;  /* items stored     */
} ring_buffer_t;

void   rb_init(ring_buffer_t *rb);
bool   rb_push(ring_buffer_t *rb, uint8_t value);   /* false if full  */
bool   rb_pop(ring_buffer_t *rb, uint8_t *out);     /* false if empty */
bool   rb_peek(const ring_buffer_t *rb, uint8_t *out);   /* false if empty */
bool   rb_is_empty(const ring_buffer_t *rb);
bool   rb_is_full(const ring_buffer_t *rb);
size_t rb_count(const ring_buffer_t *rb);

#endif
