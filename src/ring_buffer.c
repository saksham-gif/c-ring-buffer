#include "ring_buffer.h"

void rb_init(ring_buffer_t *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

bool rb_push(ring_buffer_t *rb, uint8_t value) {
    if (rb_is_full(rb)) {
        return false;
    }
    rb->data[rb->head] = value;
    rb->head = (rb->head + 1) % RB_CAPACITY;
    rb->count++;
    return true;
}

bool rb_pop(ring_buffer_t *rb, uint8_t *out) {
    if (rb_is_empty(rb)) {
        return false;
    }
    *out = rb->data[rb->tail];
    rb->tail = (rb->tail + 1) % RB_CAPACITY;
    rb->count--;
    return true;
}

bool rb_peek(const ring_buffer_t *rb, uint8_t *out) {
    if (rb_is_empty(rb)) {
        return false;
    }
    *out = rb->data[rb->tail];
    return true;
}

bool rb_is_empty(const ring_buffer_t *rb) { return rb->count == 0; }
bool rb_is_full(const ring_buffer_t *rb)  { return rb->count == RB_CAPACITY; }
size_t rb_count(const ring_buffer_t *rb)  { return rb->count; }
