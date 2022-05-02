/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy_mutexes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:37 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/02 21:29:48 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutexes(t_philosopher *philos, pthread_mutex_t stop_sim_lock, \
	pthread_mutex_t print_lock)
{
	uint32_t	i;
	uint32_t	amount_philo;

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
			i++;
		}
	}
	return (1);
}
