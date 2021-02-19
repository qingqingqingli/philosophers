//
// Created by qli on 17/02/2021.
//

#ifndef SUPPORT_FUNCTIONS_H
# define SUPPORT_FUNCTIONS_H
# include <sys/time.h>
# include <unistd.h>

long int	get_elapsed_milli(struct timeval *previous, struct timeval *now);
void		accurately_sleep(long int amount_to_sleep);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		ft_putnbr(long int n);

#endif