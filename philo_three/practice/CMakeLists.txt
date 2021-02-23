cmake_minimum_required(VERSION 3.17)
project(practice_1)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(practice_1 test1.c)