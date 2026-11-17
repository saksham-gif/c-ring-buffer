#include "bits.h"

/* OR with a mask turns the bit on, leaves others alone */
uint32_t set_bit(uint32_t reg, unsigned bit)    { return reg | (1u << bit); }

/* AND with an inverted mask turns the bit off */
uint32_t clear_bit(uint32_t reg, unsigned bit)  { return reg & ~(1u << bit); }

/* XOR flips the bit */
uint32_t toggle_bit(uint32_t reg, unsigned bit) { return reg ^ (1u << bit); }

/* Shift the bit down to position 0, then keep only that bit */
int is_bit_set(uint32_t reg, unsigned bit)      { return (int)((reg >> bit) & 1u); }

/* value & (value - 1) clears the lowest set bit; count how many times until 0 */
unsigned count_set_bits(uint32_t value) {
    unsigned count = 0;
    while (value) {
        value &= value - 1;
        count++;
    }
    return count;
}
