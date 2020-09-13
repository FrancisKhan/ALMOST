#!/bin/bash

# build on Linux

cd ..
#git clean -x -f -d
cmake -DCMAKE_BUILD_TYPE=Release .
make
cpack
cp -fv ./app/almost ../ALMOST/app
cp -fv almost*.deb ../ALMOST/installers
cp -fv ./tests/test_almost ../ALMOST/tests

# build on Windows

# cd ..
# git clean -x -f -d
# cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=mingw-w64_toolchain.cmake .
# make
# cd app
# makensis -V1 almost_installer.nsi
# cp -fv almost.exe ../../ALMOST/app
# cp -fv Almost_installer.exe ../../ALMOST/installers
# cp -fv ../tests/test_almost.exe ../../ALMOST/tests

