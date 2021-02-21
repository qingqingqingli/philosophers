//
// Created by qli on 17/02/2021.
//

#ifndef CLEAN_UP_H
# define CLEAN_UP_H
# include "../headers/struct.h"
# include <stdlib.h>
# include <unistd.h>

int	clean_up(t_setup *setup, t_philosopher *philos, int return_value);
int	set_mutex_dead(t_setup *setup, int return_val);

#endif