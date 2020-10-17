#!/bin/bash

cd ..

if [ ! -d "build" ]; then
    mkdir build
fi
cd build
cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    ..
make
cd ..
cd bin
cd opengl-demo-Release
./opengl-demo