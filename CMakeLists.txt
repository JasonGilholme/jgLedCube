cmake_minimum_required(VERSION 3.0)

#
# Setup the toolchain for the project
#
include(cmake/toolchain.cmake)

project(jgLedCube)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(jgLedCube)

