//
// Created by qli on 24/02/2021.
//

#ifndef CHECK_DEATH_H
# define CHECK_DEATH_H
# include "struct.h"
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>

int		create_check_death_thread(t_setup *setup, t_philosopher *philos);

#endif
