cmake_minimum_required (VERSION 3.10)
# Make an automatic library - will be static or dynamic based on user setting
add_library(utilities_library numeric_tools.cpp PolynomialFunction.cpp 
            additionalPrintFuncs.cpp plot.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(utilities_library PUBLIC .)
target_include_directories(utilities_library PUBLIC ../Backbone/)
target_include_directories(utilities_library PUBLIC ../Backbone/IO)
target_include_directories(utilities_library PUBLIC ../Backbone/Datamodel)
target_include_directories(utilities_library PUBLIC ../Backbone/Library)
target_include_directories(utilities_library PUBLIC ../external/boost-lib/src/boost)
target_include_directories(utilities_library PUBLIC ../external/eigen-lib/src/eigen)
target_include_directories(utilities_library PUBLIC ../external/spdlog-lib/src/spdlog/include/)
target_include_directories(utilities_library PUBLIC ../external/sciplot-lib/src/sciplot/)

# Experimental/filesystem C++ library
target_link_libraries(utilities_library -lstdc++fs)

# All users of this library will need at least C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

target_compile_features(utilities_library PUBLIC cxx_std_17)

IF (WIN32)
  target_compile_options(utilities_library PUBLIC -Wall -Wno-ignored-attributes -Wa,-mbig-obj)
ELSE()
  target_compile_options(utilities_library PUBLIC -Wall -Wno-ignored-attributes)
ENDIF()
