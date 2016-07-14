cmake_minimum_required(VERSION 2.8)

project( mathLib )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
file(GLOB_RECURSE sources src/*.cpp src/*.h)
add_executable(mathLib ${sources})



