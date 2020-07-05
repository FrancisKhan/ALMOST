cmake_minimum_required (VERSION 3.10)
# Make an automatic library - will be static or dynamic based on user setting
add_library(heat_library SlabHeatCode.cpp BaseHeatCode.cpp HeatSolver.cpp
            CylHeatCode.cpp SphHeatCode.cpp HeatCodeFactory.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(heat_library PUBLIC .)
target_include_directories(core_library PUBLIC ../Utilities)
target_include_directories(heat_library PUBLIC ../Backbone/Library)
target_include_directories(heat_library PUBLIC ../Backbone/Datamodel)

# Experimental/filesystem C++ library
target_link_libraries(heat_library -lstdc++fs utilities_library)

# All users of this library will need at least C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

target_compile_features(heat_library PUBLIC cxx_std_17)
target_compile_options(heat_library PUBLIC -Wall -Wno-ignored-attributes)
