//
// Created by qli on 17/02/2021.
//

#ifndef PRINT_H
# define PRINT_H
# include "struct.h"
# include <stdio.h>

# define RESET			"\033[0m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"

int		print_prompt(t_philosopher *philo, char *prompt);

#endif