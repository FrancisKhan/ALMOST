# ALMOST
Advanced Lightweight Multi-physics Object-oriented Simulation Tool

Dependencies for Ubuntu 18.04:

sudo apt-get install -y git\
sudo apt-get install -y cmake\
sudo apt-get install -y g++\
sudo apt-get install -y valgrind \
sudo apt-get install -y mingw-w64 

Choose posix after the following commands:

sudo update-alternatives --config i686-w64-mingw32-gcc \
sudo update-alternatives --config i686-w64-mingw32-g++ \
sudo update-alternatives --config x86_64-w64-mingw32-gcc \
sudo update-alternatives --config x86_64-w64-mingw32-g++

Download and compilation:

git clone https://github.com/FrancisKhan/ALMOST.git \
cd ALMOST\
cmake -DCMAKE_BUILD_TYPE=Release . \
make


To run all the google tests:

ctest -VV 

To run an almost calculation on Linux:

./app/almost inputs/coupledTest1.txt outputs/Out_coupledTest1.txt CRITICAL

To run an almost calculation on Windows:

almost.exe inputs/coupledTest1.txt outputs/Out_coupledTest1.txt CRITICAL

There are 5 different levels of logging:

CRITICAL \
ERROR \
WARN \
INFO \
DEBUG \
TRACE


