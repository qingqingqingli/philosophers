//
// Created by qli on 17/02/2021.
//

#include "../headers/print.h"
#include "../headers/time_calculation.h"
#include "../headers/libft_functions.h"
#include "../headers/clean_up.h"

int	print_prompt(t_philosopher *philo, char *prompt)
{
	char	*color[6];

	color[0] = RED;
	color[1] = GREEN;
	color[2] = YELLOW;
	color[3] = BLUE;
	color[4] = MAGENTA;
	color[5] = CYAN;

	if (philo->setup->life_status == dead)
		exit (0);
	if (sem_wait(philo->setup->write_sema))
		return (set_sema_dead(philo->setup, 1));
	gettimeofday(&philo->now, NULL);
	write(STDOUT_FILENO, color[philo->num % 6], ft_strlen(color[philo->num % 6]));
	write(STDOUT_FILENO, "[", 1);
	ft_putnbr(get_elapsed_milli(&philo->begin_time, &philo->now));
	write(STDOUT_FILENO, "] \t", 3);
	write(STDOUT_FILENO, "[", 1);
	ft_putnbr(philo->num);
	write(STDOUT_FILENO, "] \t", 3);
	write(STDOUT_FILENO, prompt, ft_strlen(prompt));
	sem_post(philo->setup->write_sema);
	return (0);
}
