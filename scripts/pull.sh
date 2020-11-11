#!/bin/bash

git submodule update --init --recursive

cd ..

cd lib/imgui
git checkout docking

cd ../..

cd lib/spdlog
git checkout master