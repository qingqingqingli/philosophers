//
// Created by qli on 23/02/2021.
//

#ifndef FORK_PHILO_PROCESS_H
# define FORK_PHILO_PROCESS_H
# include "../headers/struct.h"
# include <unistd.h>
# include <sys/wait.h>

int	fork_philo_process(t_setup *setup, t_philosopher *philos);

#endif
