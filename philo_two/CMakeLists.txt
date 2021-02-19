cmake_minimum_required(VERSION 3.17)
project(philo_two)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(philo_two )