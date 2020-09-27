cmake_minimum_required (VERSION 3.10)

include( Munkei.cmake )
include( MunkeiVersionFromGit )

# Use it
version_from_git(
  LOG       ON
  TIMESTAMP "%Y%m%d%H%M%S"
)

# Use the full semantic version for things like packag

project(almost
    VERSION ${VERSION}
    DESCRIPTION "ALMOST"
    LANGUAGES CXX)
	
# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall")

set(VERSION "#ifndef GIT_VERSION_H
#define GIT_VERSION_H

#include <string>

const std::string VERSION_ALL   =\"${VERSION}\";
const std::string VERSION_MAJOR =\"${VERSION_MAJOR}\";
const std::string VERSION_MINOR =\"${VERSION_MINOR}\";
const std::string VERSION_PATCH =\"${VERSION_PATCH}\";

#endif")

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Backbone/IO/git-version.h)
    file(READ ${CMAKE_CURRENT_SOURCE_DIR}/Backbone/IO/git-version.h VERSION_)
else()
    set(VERSION_ "")
endif()

if (NOT "${VERSION}" STREQUAL "${VERSION_}")
    file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Backbone/IO/git-version.h "${VERSION}")
endif()

include(CTest)

# External library directory
add_subdirectory(external)

# Backbone directory
add_subdirectory(Backbone)

# Transport directory
add_subdirectory(CPM)

# Point kinetics directory
add_subdirectory(CORE)

# Heat transfer directory
add_subdirectory(Heat)

# Heat transfer directory
add_subdirectory(Diffusion)

# Utilities files are here
add_subdirectory(Utilities)

# The executable code is here
add_subdirectory(app)

# Tests are here
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

# experimental stuff

#install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/
#    DESTINATION ${CMAKE_SOURCE_DIR}/include
#    FILES_MATCHING PATTERN "*.h*")
	
#install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/
#    DESTINATION ${CMAKE_SOURCE_DIR}/lib
#    FILES_MATCHING PATTERN "*.a")
