/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_threads.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:37 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/14 14:26:42 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_philosopher *philos)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philos[i].pd->stop_sim_lock);
	pthread_mutex_destroy(&philos[i].pd->print_lock);
	while (i < philos[i].pd->amount_philo)
	{
		pthread_mutex_destroy(&philos[i].pd->forks[i]);
		pthread_mutex_destroy(&philos[i].amount_meals_lock);
		pthread_mutex_destroy(&philos[i].stop_sim_lock_local);
		i++;
	}
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
