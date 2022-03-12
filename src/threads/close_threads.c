/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_threads.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:37 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/12 09:42:36 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	destroy_mutexes(t_program_data *pd)
{
	int i;

	i = 0;
	while (i < pd->amount_philo)
	{
		pthread_mutex_destroy(&pd->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&pd->stop_sim_lock);
	pthread_mutex_destroy(&pd->print_lock);
}

void	close_threads(t_program_data *pd)
{
	int	i;

	i = 0;
	while (i < pd->amount_philo)
	{
		pthread_join(pd->philo_threads[i], NULL);
		i++;
	}
}
