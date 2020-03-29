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

# ExternalProject_Add_Step(
    # eigen
    # copySource
    # COMMAND ${CMAKE_COMMAND} -E copy_directory src/eigen/Eigen Eigen
    # COMMENT "Copying Eigen"
# )

# ExternalProject_Add_Step(
    # eigen
    # copySource
    # COMMAND ${CMAKE_COMMAND} -E copy_directory external/src/eigen/unsupported external/unsupported
    # COMMENT "Copying unsupported"
# )
# ExternalProject_Add_Step(
    # eigen_remove
    # removeSource
    # WORKING_DIRECTORY ${MONOENGINE_DIR}
    # DEPENDEES copySource
    # COMMAND ${CMAKE_COMMAND} -E remove_directory MonoEngineSource
    # COMMENT "Removing MonoEngineSourcefolder"
# )

#add_custom_target(demo tar -xzf ${CMAKE_BINARY_DIR}/demo/src/bunny.tar.gz -C ${CMAKE_BINARY_DIR}/demo)

#add_dependencies(almost eigen)
