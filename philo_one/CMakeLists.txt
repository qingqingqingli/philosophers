cmake_minimum_required(VERSION 3.17)
project(practice)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(practice libft/libft.a libft/libft.h main.c philo_one.h support_functions/support_01.c init_program_setup.c create_philosophers.c clean_up.c libft/srcs/ft_atoi.c)