//
// Created by qli on 08/02/2021.
//

#include "philo_one.h"

void 	start_action(t_setup_data data)
{
	struct timeval 	begin_time;
	struct timeval 	finish_time;
	long int		time_difference = 0;

	gettimeofday(&begin_time, NULL);
	usleep(50);
	gettimeofday(&finish_time, NULL);
	time_difference = finish_time.tv_usec - begin_time.tv_usec;
	printf(BLUE "time difference [%ld]\n", time_difference);
	printf(RESET);
}

int 	main(int argc, char **argv)
{
	t_setup_data setup_data;

	if (init_program_setup(argc, argv, &setup_data) == -1)
		return (-1);
	start_action(setup_data);
	return (0);
}
