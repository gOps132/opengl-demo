#!/bin/bash

git submodule update --init --recursive
cd lib/imgui
git checkout cmake
cd ..

cd imgui-test
git checkout docking