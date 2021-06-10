# Copyright (C) 2002-2020 CERN for the benefit of the ATLAS collaboration
#
# Project file for building a selected set of packages against an
# installed ATLAS release/nightly.
#

# Set up the project.
cmake_minimum_required( VERSION 3.10 )
# Note that there is a second `project` call further below to set
# the version and languages.
project( AnalysisProject )

# Let the user pick up updated AtlasCMake/AtlasLCG versions for testing.
# Remember that it's not a problem if AtlasCMake is not found, that's why
# we use the QUIET keyword.
find_package( AtlasCMake QUIET )

# Try to figure out what project is our parent. Just using a hard-coded list
# of possible project names. Basically the names of all the other
# sub-directories inside the Projects/ directory in the repository.
set( _parentProjectNames Athena AthenaP1 AnalysisBase AthAnalysis
   AthSimulation AthDerivation AthDataQuality AthGeneration )
set( _defaultParentProject Athena )
foreach( _pp ${_parentProjectNames} )
   if( NOT "$ENV{${_pp}_DIR}" STREQUAL "" )
      set( _defaultParentProject ${_pp} )
      break()
   endif()
endforeach()

# Set the parent project name based on the previous findings:
set( ATLAS_PROJECT ${_defaultParentProject}
   CACHE STRING "The name of the parent project to build against" )

# Clean up:
unset( _parentProjectNames )
unset( _defaultParentProject )

# Find the project that we depend on:
find_package( ${ATLAS_PROJECT} REQUIRED )

# Set up the project with its version and baseline languages.
project( AnalysisProject VERSION ${${ATLAS_PROJECT}_VERSION} LANGUAGES C CXX )

# Set up where to find the AthenaPoolUtilitiesTest CMake code.
if( IS_DIRECTORY
   "${CMAKE_SOURCE_DIR}/../../Database/AthenaPOOL/AthenaPoolUtilities" )
   set( AthenaPoolUtilitiesTest_DIR
      "${CMAKE_SOURCE_DIR}/../../Database/AthenaPOOL/AthenaPoolUtilities/cmake"
      CACHE PATH "Directory holding the AthenaPoolUtilititesTest module" )
endif()

# Set up where to find the xAODUtilities CMake code.
if( IS_DIRECTORY
   "${CMAKE_SOURCE_DIR}/../../Event/xAOD/xAODCore/cmake" )
   set( xAODUtilities_DIR
      "${CMAKE_SOURCE_DIR}/../../Event/xAOD/xAODCore/cmake"
      CACHE PATH "Directory holding the xAODUtilities module" )
endif()

# Set up CTest:
atlas_ctest_setup()

# Generate a compile_commands.json file, which VS Code can use to interpret
# our code correctly.
set( CMAKE_EXPORT_COMPILE_COMMANDS TRUE CACHE BOOL
   "Create compile_commands.json" FORCE )

# Set up a work directory project with the same version as our parent:
atlas_project( USE ${ATLAS_PROJECT} ${${ATLAS_PROJECT}_VERSION}
   PROJECT_ROOT ${CMAKE_SOURCE_DIR}/../../ )

# Set up the runtime environment setup script(s):
lcg_generate_env( SH_FILE ${CMAKE_BINARY_DIR}/${ATLAS_PLATFORM}/env_setup.sh )
install( FILES ${CMAKE_BINARY_DIR}/${ATLAS_PLATFORM}/env_setup.sh
   DESTINATION . )

# Dump some environment variables for IDE use:
set( CMAKE_DUMP_ENV_FILE ${CMAKE_BINARY_DIR}/env.txt CACHE FILEPATH
   "File containing dump of environment variables" )

if( CMAKE_DUMP_ENV_FILE )
   execute_process(
      COMMAND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/atlas_build_run.sh printenv
      COMMAND grep -w ^PYTHONPATH
      OUTPUT_FILE "${CMAKE_DUMP_ENV_FILE}" )
endif()

add_executable(MyExample myexec.cpp)

find_package(pybind11)

# Set up CPack:
atlas_cpack_setup()

# Remind to set up the environment
message( STATUS "")
message( STATUS "            In order to test your updates, please don't forget to" )
message( STATUS "            set up the environment with e.g.:" )
message( STATUS "            --->   source ${ATLAS_PLATFORM}/setup.sh" )
message( STATUS "")
