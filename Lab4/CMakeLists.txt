cmake_minimum_required(VERSION 3.3)
project(Lab4)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES qtest.c queue.c)
add_executable(Lab4 ${SOURCE_FILES})
