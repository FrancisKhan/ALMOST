cmake_minimum_required (VERSION 3.10)
# Make an automatic library - will be static or dynamic based on user setting
add_library(backbone_library numeric_tools.cpp  AbstractMaterial.cpp
			Mesh.cpp Output.cpp Input.cpp Uranium.cpp KineticsSet.cpp
			AbstractGeometry.cpp Cylinder.cpp Sphere.cpp Slab.cpp
			AbstractSolver.cpp Library.cpp CrossSectionSet.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(backbone_library PUBLIC .)
target_include_directories(backbone_library PUBLIC ../../external)
target_include_directories(backbone_library PUBLIC ../../external/boost-lib/src/boost)
target_include_directories(backbone_library PUBLIC ../../external/eigen-lib/src/eigen)
target_include_directories(backbone_library PUBLIC ../../external/spdlog/include/)

# This depends on (header only) boost
#target_link_libraries(cpm_library PRIVATE Boost::boost)

# Experimental/filesystem C++ library
target_link_libraries(backbone_library -lstdc++fs)

# All users of this library will need at least C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#target_compile_features(cpm_library PUBLIC cxx_std_17)
target_compile_options(backbone_library PUBLIC -Wall -Wno-ignored-attributes)
