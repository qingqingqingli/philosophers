//
// Created by qli on 17/02/2021.
//

#include "../headers/time_calculation.h"

long int get_elapsed_milli(struct timeval *previous, struct timeval *now)
{
	return ((now->tv_sec - previous->tv_sec) * 1000000 + (now->tv_usec - previous->tv_usec)) / 1000;
}
