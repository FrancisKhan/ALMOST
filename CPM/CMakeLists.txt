cmake_minimum_required (VERSION 3.10)
# Make an automatic library - will be static or dynamic based on user setting
add_library(cpm_library BaseSpectrumCode.cpp SpectrumCodeFactory.cpp
			CylSpectrumCode.cpp SphSpectrumCode.cpp SlabSpectrumCode.cpp
			SpectrumSolver.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(cpm_library PUBLIC .)
target_include_directories(cpm_library PUBLIC ../Utilities)
target_include_directories(cpm_library PUBLIC ../Backbone/Library)
target_include_directories(cpm_library PUBLIC ../Backbone/Datamodel)

# This depends on (header only) boost
#target_link_libraries(cpm_library PRIVATE Boost::boost)

# Experimental/filesystem C++ library
target_link_libraries(cpm_library -lstdc++fs utilities_library)

# All users of this library will need at least C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#target_compile_features(cpm_library PUBLIC cxx_std_17)
target_compile_options(cpm_library PUBLIC -Wall -Wno-ignored-attributes)
