cmake_minimum_required(VERSION 3.17)
project(philo_three)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(philo_three main.c srcs/check_status.c srcs/clean_up.c srcs/initialise_philos.c srcs/libft_functions.c srcs/print.c srcs/process_input.c srcs/time_calculation.c srcs/start_action.c srcs/fork_philo_process.c headers/fork_philo_process.h srcs/check_death.c headers/check_death.h)