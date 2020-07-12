cmake_minimum_required(VERSION 3.16)
project(filecomparator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

cmake_policy(SET CMP0060 NEW)

add_subdirectory( sources )
add_subdirectory( dependencies )
