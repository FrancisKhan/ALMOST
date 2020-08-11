# Tests need to be added as executables first
add_executable(test_almost mathsTests.cpp CoreTests.cpp HeatIntegrationTests.cpp 
               CPMIntegrationTests.cpp CoreIntegrationTests.cpp
               CoupledIntegrationTests.cpp)

# I'm using C++17 in the test
#target_compile_features(test_almost PRIVATE cxx_std_17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

target_link_libraries(test_almost PRIVATE utilities_library backbone_library core_library cpm_library gtest gtest_main pthread)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME test_almost_test COMMAND $<TARGET_FILE:test_almost>) # Command can be a target
