# c-ring-buffer

![CI](https://github.com/saksham-gif/c-ring-buffer/actions/workflows/ci.yml/badge.svg)

A fixed-size circular (ring) buffer in C11, the data structure firmware uses for
UART receive buffers and producer/consumer queues.

## Features
- O(1) push and pop with wrap-around
- Full/empty detection with a count field
- Unit tests for FIFO order, overflow, underflow and wrap-around

## Build & test (Linux)
    make test        # or: ./run_tests.sh

## Tools
C11, GCC (-Wall -Wextra -Werror), GNU Make, Bash, GitHub Actions CI
