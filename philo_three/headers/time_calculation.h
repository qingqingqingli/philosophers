//
// Created by qli on 17/02/2021.
//

#ifndef TIME_CALCULATION_H
# define TIME_CALCULATION_H
# include <sys/time.h>

long int	get_elapsed_milli(struct timeval *previous, struct timeval *now);
void		accurately_sleep(long int amount_to_sleep);

#endif