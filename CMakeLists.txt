cmake_minimum_required(VERSION 3.3)
project(I3DOA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(lib)
include_directories(src)
set(SOURCE_FILES main.cpp)

add_executable(I3DOA ${SOURCE_FILES})