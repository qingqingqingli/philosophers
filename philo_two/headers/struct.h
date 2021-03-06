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

# define SEMA_ERROR "semaphore process error\n"
# define FORK_SEMA "fork_sema"
# define WRITE_SEMA "write_sema"
# define CHECK_STATUS_SEMA "check_status_sema"
# define MODE 0644

typedef struct s_setup
{
	int				number_of_philosophers;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				life_status;
	int				sema_status;
	sem_t			*fork_sema;
	sem_t			*check_status_sema;
	sem_t			*write_sema;
}					t_setup;

typedef struct s_philosopher
{
	t_setup			*setup;
	int				num;
	int				time_of_eaten;
	struct timeval	begin_time;
	struct timeval	now;
	struct timeval	last_eat_time;
	pthread_t		philo_thread;
	pthread_t		philo_status_thread;
}					t_philosopher;

enum e_values
{
	alive = 1,
	dead = 0
};

#endif