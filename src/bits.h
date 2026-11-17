#ifndef BITS_H
#define BITS_H

#include <stdint.h>

uint32_t set_bit(uint32_t reg, unsigned bit);
uint32_t clear_bit(uint32_t reg, unsigned bit);
uint32_t toggle_bit(uint32_t reg, unsigned bit);
int      is_bit_set(uint32_t reg, unsigned bit);
unsigned count_set_bits(uint32_t value);

#endif

