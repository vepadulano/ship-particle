# Copyright (C) 1995-2023, Rene Brun and Fons Rademakers.
# All rights reserved.
#
# For the licensing terms see $ROOTSYS/LICENSE.
# For the list of contributors see $ROOTSYS/README/CREDITS.

#####################################################################################################################

# Details about integrating ROOT into CMake projects:
#     https://root.cern/manual/integrate_root_into_my_cmake_project/

#####################################################################################################################

# CMakeLists.txt that creates a library with dictionary and a main program
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(treeUsingCustomClass)

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS Tree RIO EG)

#---Include a CMake module which makes use of the previous variables and loads modules 
#   with useful macros or functions such as ROOT_GENERATE_DICTIONARY
#   For further details: https://root-forum.cern.ch/t/how-to-integrate-root-into-my-project-with-cmake/37175
include(${ROOT_USE_FILE})

#---Add include directory of ROOT to the build
include_directories(${CMAKE_SOURCE_DIR})

# CMake function provided by ROOT, used to generate the dictionary file, G__userClass.cxx
#     See this link for further details:
#     https://root.cern/manual/io_custom_classes/#using-cmake
ROOT_GENERATE_DICTIONARY(G__ShipParticle ShipParticle.h ShipParticle.cxx LINKDEF ShipParticleLinkDef.h)

#---Create a shared library from
#   * the previously generated dictionary, G__userClass.cxx
add_library(ShipParticleLib SHARED G__ShipParticle.cxx)
target_link_libraries(ShipParticleLib ${ROOT_LIBRARIES} EG)
add_dependencies(ShipParticleLib G__ShipParticle)

#---Create  a main program using the library
add_executable(repro.out repro.cpp)
target_link_libraries(repro.out ${ROOT_LIBRARIES} ShipParticleLib)
