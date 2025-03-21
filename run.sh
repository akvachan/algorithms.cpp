#!/bin/sh

set -euxo pipefail

cmake -B build
cmake --build build --parallel 10

build/Algorithms
