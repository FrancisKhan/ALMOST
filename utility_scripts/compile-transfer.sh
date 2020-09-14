#!/bin/bash

### build on Linux

cd ..
git clean -x -f -d
cmake -DCMAKE_BUILD_TYPE=Release .
make
cpack

# copy executables and installers

cp -fv ./app/almost ../ALMOST/app
cp -fv almost*.deb ../ALMOST/installers
cp -fv ./tests/test_almost ../ALMOST/tests

### build on Windows

cd ..
git clean -x -f -d
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=mingw-w64_toolchain.cmake .
make
cd app
makensis -V1 almost_installer.nsi

# get last tag
cd ..
FullTag=`git describe --abbrev=0`
Tag=${FullTag:1}
cd app

# copy executables and installers

cp -fv almost.exe ../../ALMOST/app
cp -fv Almost_installer.exe ../../ALMOST/installers/Almost-${Tag}_installer.exe
cp -fv ../tests/test_almost.exe ../../ALMOST/tests

