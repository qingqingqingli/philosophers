//
// Created by qli on 17/02/2021.
//

#pragma once
#include <sys/time.h> // gettimeofday
#include <unistd.h>

long int	get_elapsed_milli(struct timeval *previous, struct timeval *now);
void 		accurately_sleep(long int amount_to_sleep);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
