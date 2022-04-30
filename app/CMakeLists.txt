add_executable(almost main.cpp)
#target_compile_features(app PRIVATE cxx_std_14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

IF (WIN32)
  SET(CMAKE_EXE_LINKER_FLAGS "-static")
ENDIF()

target_link_libraries(almost PRIVATE utilities_library backbone_library cpm_library 
                                    core_library heat_library diffusion_library
                                    ads_library)

install(TARGETS almost
    DESTINATION "/usr/bin/"
)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "FrancisKhan")
SET(CPACK_PACKAGE_DESCRIPTION "Advanced Lightweight Multi-physics Object-oriented Simulation Tool")
#SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "It's a service menu for dolphin that allow you to open folders skipping no-text files")
SET(CPACK_PACKAGE_CONTACT "tntfnc3@gmail.com")
SET(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
SET(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
SET(CPACK_DEBIAN_ARCHITECTURE "amd64")
INCLUDE(CPack)
