//
// Created by qli on 17/02/2021.
//

#pragma once
#include <sys/time.h> // gettimeofday
#include <unistd.h>

int			get_elapsed_milli(struct timeval *previous, struct timeval *now);
int			ft_atoi(const char *str);
void 		accurately_sleep(long int amount_to_sleep);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
void		ft_putnbr_fd(int n, int fd);