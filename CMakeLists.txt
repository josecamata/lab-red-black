cmake_minimum_required(VERSION 3.0.0)
project(redblack VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(librb)
add_subdirectory(librb)
add_subdirectory(tests)
