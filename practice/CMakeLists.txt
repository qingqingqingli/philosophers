cmake_minimum_required(VERSION 3.17)
project(practice)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -pthread")

add_executable(practice mutex_switch.c)
