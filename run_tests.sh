#!/usr/bin/env bash
# Builds the project from scratch and runs the unit tests.
set -euo pipefail

echo "== Cleaning =="
make clean

echo "== Building =="
make

echo "== Running tests =="
if make test; then
    echo "All tests passed ✅"
else
    echo "Tests failed ❌"
    exit 1
fi
