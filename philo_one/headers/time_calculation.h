//
// Created by qli on 17/02/2021.
//

#pragma once
#include <sys/time.h> // gettimeofday

long int get_elapsed_milli(struct timeval *previous, struct timeval *now);