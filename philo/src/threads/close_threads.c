/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_threads.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:37 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/25 16:42:14 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	destroy_mutexes(t_philosopher *philos, pthread_mutex_t stop_sim_lock, pthread_mutex_t print_lock)
{
	int	i;
	int	amount_philo;

	i = 0;
	amount_philo = philos[0].pd->amount_philo;
	pthread_mutex_destroy(&stop_sim_lock);
	pthread_mutex_destroy(&print_lock);
	if (philos)
	{
		while (i < amount_philo)
		{
			pthread_mutex_destroy(&philos[i].pd->forks[i]);
			pthread_mutex_destroy(&philos[i].amount_meals_lock);
			pthread_mutex_destroy(&philos[i].stop_sim_lock_local);
			i++;
		}
	}
	return (1);
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
