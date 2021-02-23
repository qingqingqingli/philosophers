//
// Created by qli on 23/02/2021.
//

#ifndef FORK_CHILD_PROCESS_H
# define FORK_CHILD_PROCESS_H
# include "../headers/struct.h"

void	wait_for_child_processes(t_philosopher *philos, int num);
int		fork_philo_processes(t_philosopher *philos, int num);

#endif
