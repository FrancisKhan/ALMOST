add_executable(app main.cpp)
#target_compile_features(app PRIVATE cxx_std_14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

target_link_libraries(app PRIVATE backbone_library cpm_library core_library)
