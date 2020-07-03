# ALMOST
Advanced Lightweight Multi-physics Object-oriented Simulation Tool

Dependencies for Ubuntu 18.04:

sudo apt-get install -y git\
sudo apt-get install -y cmake\
sudo apt-get install -y g++\
sudo apt-get install -y valgrind

Download and compilation:

git clone https://github.com/FrancisKhan/ALMOST.git\
cd ALMOST\
cmake .\
make


To run all the google tests:

ctest -VV 
