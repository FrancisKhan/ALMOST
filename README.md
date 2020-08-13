# ALMOST
Advanced Lightweight Multi-physics Object-oriented Simulation Tool

Dependencies for Ubuntu 18.04:

sudo apt-get install -y git\
sudo apt-get install -y cmake\
sudo apt-get install -y g++\
sudo apt-get install -y valgrind \
sudo apt-get install gcc-mingw-w64

Download and compilation:

git clone https://github.com/FrancisKhan/ALMOST.git \
cd ALMOST\
cmake -DCMAKE_BUILD_TYPE=Release . \
make


To run all the google tests:

ctest -VV 

To run an almost calculation:

./app/almost inputs/heat-neutronics.txt outputs/Out_heat-neutronics.txt DEBUG

There are 5 different levels of logging:

CRITICAL \
ERROR \
WARN \
INFO \
DEBUG \
TRACE


