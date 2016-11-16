# CMake Root dir
cmake_minimum_required (VERSION 3.1)
set( CMAKE_VERBOSE_MAKEFILE on )
project (MPIMag C CXX)

find_package(MPI)
include_directories(SYSTEM ${MPI_INCLUDE_PATH})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set (CMAKE_CXX_STANDARD 11)
set (CXXMag_VERSION_MAJOR 0)
set (CXXMag_VERSION_MINOR 1)

add_subdirectory(local/googletest-release-1.8.0/googletest)
add_subdirectory(src)
add_subdirectory(tests)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $(CMAKE_BINARY_DIR))
