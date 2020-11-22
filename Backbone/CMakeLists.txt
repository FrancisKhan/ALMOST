cmake_minimum_required (VERSION 3.10)
# Make an automatic library - will be static or dynamic based on user setting
add_library(backbone_library Datamodel/Material.cpp Datamodel/Mesh.cpp 
			IO/Output.cpp IO/Input.cpp Datamodel/KineticsSet.cpp Datamodel/AbstractGeometry.cpp 
			Datamodel/Cylinder.cpp Datamodel/Sphere.cpp Datamodel/Slab.cpp 
			Datamodel/AbstractSolver.cpp Datamodel/Reactor.cpp Library/Library.cpp
			Datamodel/Problem.cpp Datamodel/BaseCalculation.cpp
			Datamodel/SingleCalculation.cpp Datamodel/DoubleCalculation.cpp
			Datamodel/SolverData.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(backbone_library PUBLIC Datamodel)
target_include_directories(backbone_library PUBLIC IO)
target_include_directories(backbone_library PUBLIC Library)
target_include_directories(backbone_library PUBLIC ../Utilities)
target_include_directories(backbone_library PUBLIC ../CPM)
target_include_directories(backbone_library PUBLIC ../CORE)
target_include_directories(backbone_library PUBLIC ../Heat)
target_include_directories(backbone_library PUBLIC ../Diffusion)

# This depends on (header only) boost
#target_link_libraries(cpm_library PRIVATE Boost::boost)

# Experimental/filesystem C++ library
target_link_libraries(backbone_library -lstdc++fs utilities_library)

# All users of this library will need at least C++17

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#target_compile_features(cpm_library PUBLIC cxx_std_17)
target_compile_options(backbone_library PUBLIC -Wall -Wno-ignored-attributes)
