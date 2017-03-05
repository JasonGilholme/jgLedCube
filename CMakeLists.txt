cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

#
# Setup the toolchain for the project
#
include(cmake/toolchain.cmake)

project(jgLedCube)
include(cmake/dependencies.cmake)
add_subdirectory(jgLedCube)
