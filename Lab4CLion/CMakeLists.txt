cmake_minimum_required(VERSION 3.3)
project(Lab4CLion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Lab4CLion ${SOURCE_FILES})