cmake_minimum_required(VERSION 3.17)
project(rewrite)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(rewrite headers/struct.h main.c srcs/process_input.c headers/process_input.h srcs/libft/srcs/ft_atoi.c srcs/libft/libft.h srcs/initialise_philos.c headers/initialise_philos.h srcs/clean_up.c headers/clean_up.h)