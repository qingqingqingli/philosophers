cmake_minimum_required(VERSION 3.17)
project(philo_one)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(philo_one headers/struct.h main.c srcs/process_input.c headers/process_input.h srcs/initialise_philos.c headers/initialise_philos.h srcs/clean_up.c headers/clean_up.h srcs/start_action.c headers/start_action.h srcs/check_status.c headers/check_status.h srcs/time_calculation.c headers/time_calculation.h srcs/print.c headers/print.h srcs/grab_forks.c headers/grab_forks.h srcs/libft_functions.c headers/libft_functions.h)