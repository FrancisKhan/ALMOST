cmake_minimum_required (VERSION 3.10)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

ExternalProject_Add(
    eigen 
    PREFIX "eigen-lib"
    URL https://gitlab.com/libeigen/eigen/-/archive/master/eigen-master.tar.gz
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

ExternalProject_Add(
    boost 
    PREFIX "boost-lib"
    URL https://vorboss.dl.sourceforge.net/project/boost/boost/1.72.0/boost_1_72_0.tar.bz2
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

ExternalProject_Add(
    spdlog 
    PREFIX "spdlog-lib"
    URL https://codeload.github.com/gabime/spdlog/zip/v1.x
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)