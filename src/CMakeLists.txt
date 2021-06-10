# Copyright (C) 2002-2021 CERN for the benefit of the ATLAS collaboration
#
# Build configuration for the tutorial project.
#

# Set up the project.
cmake_minimum_required( VERSION 3.18 )
project( AnalysisDemo VERSION 1.0.0 LANGUAGES CXX )

# Find the base project.
find_package( AnalysisBase 22.2 REQUIRED )

# Set up the project's custom CMake code.
list( PREPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" )

# Set up CTest.
atlas_ctest_setup()

# Generate a compile_commands.json file, which VS Code can use to interpret
# our code correctly.
set( CMAKE_EXPORT_COMPILE_COMMANDS TRUE CACHE BOOL
   "Create compile_commands.json" FORCE )

find_package(Python COMPONENTS Interpreter Development REQUIRED)
add_subdirectory(pybind11 EXCLUDE_FROM_ALL)
add_subdirectory(bindings)

message(STATUS "${Python_LIBRARIES}")

# Set the ATLAS project, for building all packages in the repository.
atlas_project( USE AnalysisBase 22.2 )

# Set up the runtime environment setup script(s).
lcg_generate_env( SH_FILE ${CMAKE_BINARY_DIR}/${ATLAS_PLATFORM}/env_setup.sh )
install( FILES ${CMAKE_BINARY_DIR}/${ATLAS_PLATFORM}/env_setup.sh
   DESTINATION . )

# Set up CPack.
atlas_cpack_setup()
