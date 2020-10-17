#!/bin/bash

git submodule update --init
cd lib/imgui
git checkout cmake
cd ..

cd imgui-test
git checkout docking