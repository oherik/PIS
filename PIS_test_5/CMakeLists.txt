cmake_minimum_required(VERSION 3.3)
project(PIS_test_5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(PIS_test_5 ${SOURCE_FILES})