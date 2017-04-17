#!/bin/bash
set -ex

if [ -n "$COMPILER" ]; then
  export CXX="$COMPILER"
fi

mkdir -p build
cd build
cmake ..
make VERBOSE=1 -j2 catch_tests
./catch_tests
