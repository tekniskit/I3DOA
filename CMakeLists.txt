cmake_minimum_required(VERSION 3.3)
project(I3DOA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp vector/Vector.cpp vector/Vector.h vector/Vector_test.cpp vector/Vector_test.h node/Node.h)
add_executable(I3DOA ${SOURCE_FILES})