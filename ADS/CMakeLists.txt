cmake_minimum_required (VERSION 3.10)
# Make an automatic library - will be static or dynamic based on user setting
add_library(ads_library BaseADSCode.cpp ADSSolver.cpp ADSCodeFactory.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(ads_library PUBLIC .)
target_include_directories(ads_library PUBLIC ../Utilities)
target_include_directories(ads_library PUBLIC ../Backbone)
target_include_directories(ads_library PUBLIC ../Backbone/Library)
target_include_directories(ads_library PUBLIC ../Backbone/Datamodel)

# Experimental/filesystem C++ library
target_link_libraries(ads_library -lstdc++fs utilities_library backbone_library)

# All users of this library will need at least C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

target_compile_features(ads_library PUBLIC cxx_std_17)
target_compile_options(ads_library PUBLIC -Wall -Wno-ignored-attributes)
