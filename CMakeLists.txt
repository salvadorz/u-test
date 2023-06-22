#******************************************************************************
#*Copyright (C) 2023 by Salvador Z                                            *
#*                                                                            *
#*****************************************************************************/
#*
#*@author Salvador Z
#*@brief CMakeLists file to create a CMake project
#*
cmake_minimum_required(VERSION 3.0.0)
project(uTest
  VERSION 0.1
  DESCRIPTION "Project to create a simple and easy Unit Test Framework"
  LANGUAGES C CXX ASM)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

### General Configuration ###

set_property(GLOBAL PROPERTY C_STANDARD   11)
set_property(GLOBAL PROPERTY CXX_STANDARD 17)

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

### Compiler Flags Configuration ###

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-O3")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/)

# Create an output dir in CMAKE_BINARY_DIR
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

# Use this directory to test and emulate a filesystem env
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/artifacts CACHE PATH "Installation Directory")


### Project Source Tree ###
add_subdirectory("lib")