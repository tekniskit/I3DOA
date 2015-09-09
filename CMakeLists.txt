cmake_minimum_required(VERSION 3.3)
project(I3DOA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp vector/Vector.cpp vector/Vector.h node/Node.h LLToolkit/LLToolkit.h stack/Stack.h queue/Queue.h queue/PriorityQueue.h)
add_executable(I3DOA ${SOURCE_FILES})