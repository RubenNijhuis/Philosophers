/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy_mutexes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:37 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/08 12:41:31 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdint.h>

int32_t	destroy_mutexes(t_philosopher *philos, pthread_mutex_t stop_sim_lock, \
	pthread_mutex_t print_lock)
{
	size_t		i;
	uint32_t	amount_philos;

	i = 0;
	amount_philos = philos[0].pd->amount_philos;
	pthread_mutex_destroy(&stop_sim_lock);
	pthread_mutex_destroy(&print_lock);
	if (philos)
	{
		while (i < amount_philos)
		{
			pthread_mutex_destroy(&philos[i].pd->forks[i]);
			pthread_mutex_destroy(&philos[i].amount_meals_lock);
			i++;
		}
	}
	return (1);
}
