/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_up.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 09:49:19 by qli           #+#    #+#                 */
/*   Updated: 2021/02/18 09:49:19 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/clean_up.h"

void	clean_up_philos(t_philosopher *philos)
{
	if (philos)
		free(philos);
}

void	clean_up_setup(t_setup *setup)
{
	if (setup->fork_mutexs)
		free(setup->fork_mutexs);
}

int		clean_up(t_setup *setup, t_philosopher *philos, int return_value)
{
	clean_up_philos(philos);
	clean_up_setup(setup);
	return (return_value);
}
