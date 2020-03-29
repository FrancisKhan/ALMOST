cmake_minimum_required (VERSION 3.10)
project(almost
    VERSION 0.1
    DESCRIPTION "ALMOST"
    LANGUAGES CXX)
	
# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall")

include(CTest)

# The compiled library code is here
add_subdirectory(external)

# The compiled library code is here
add_subdirectory(Backbone)

# The executable code is here
add_subdirectory(CPM)

# The executable code is here
add_subdirectory(CORE)

# The executable code is here
add_subdirectory(app)

# Tests are here
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

#install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/
#    DESTINATION ${CMAKE_SOURCE_DIR}/include
#    FILES_MATCHING PATTERN "*.h*")
	
#install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/
#    DESTINATION ${CMAKE_SOURCE_DIR}/lib
#    FILES_MATCHING PATTERN "*.a")