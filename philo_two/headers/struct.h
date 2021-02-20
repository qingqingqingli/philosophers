//
// Created by qli on 17/02/2021.
//

#ifndef STRUCT_H
# define STRUCT_H
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef struct s_setup
{
	int				number_of_philosophers;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				life_status;
	sem_t 			*fork_sema;
	pthread_mutex_t	status_mutex;
	pthread_mutex_t	write_mutex;
}					t_setup;

typedef struct s_philosopher
{
	t_setup			*setup;
	int				num;
	int				time_of_eaten;
	struct timeval	begin_time;
	struct timeval	now;
	struct timeval	last_eat_time;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	pthread_t		philo_thread;
	pthread_t		philo_status_thread;
}					t_philosopher;

enum e_values
{
	alive = 1,
	dead = 0
};

#endif