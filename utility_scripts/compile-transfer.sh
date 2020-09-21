#!/bin/bash

build_linux () {
  echo "Build Almost for Linux"
  cd ..
  git clean -x -f -d
  cmake -DCMAKE_BUILD_TYPE=Release .
  make
  cpack
  cp -fv ./app/almost ../ALMOST/app
  cp -fv almost*.deb ../ALMOST/installers
  cp -fv ./tests/test_almost ../ALMOST/tests
}

build_windows () {
  echo "Build Almost for Windows"
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
  cp -fv almost.exe ../../ALMOST/app
  cp -fv Almost_installer.exe ../../ALMOST/installers/Almost-${Tag}_installer.exe
  cp -fv ../tests/test_almost.exe ../../ALMOST/tests
}

if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
fi

if [ $1 == "linux" ]; then

  build_linux
  
elif [ $1 == "windows" ]; then

  build_windows

elif [ $1 == "all" ]; then

  build_linux
  build_windows
  
else
  echo "OS system not recognized or not supported." 
  echo "Please choose between: linux, windows or all"
fi


