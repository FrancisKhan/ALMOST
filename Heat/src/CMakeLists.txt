cmake_minimum_required (VERSION 3.10)
# Make an automatic library - will be static or dynamic based on user setting
add_library(heat_library HeatCode.cpp HeatSolver.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(heat_library PUBLIC .)
target_include_directories(heat_library PUBLIC ../../Backbone/src/)
target_include_directories(heat_library PUBLIC ../../external/spdlog-lib/src/spdlog/include/)
target_include_directories(heat_library PUBLIC ../../external/eigen-lib/src/eigen)
#target_include_directories(heat_library PUBLIC ../../external/boost-lib/src/boost)

# Experimental/filesystem C++ library
target_link_libraries(heat_library -lstdc++fs)

# All users of this library will need at least C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#target_compile_features(cpm_library PUBLIC cxx_std_17)
target_compile_options(heat_library PUBLIC -Wall -Wno-ignored-attributes)
