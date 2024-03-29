/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_threads.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:58 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/08 12:34:15 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdint.h>

bool	make_philo_thread(t_philosopher *philos, t_program_data *pd, \
	uint32_t id)
{
	philos[id].pd = pd;
	philos[id].id = id + 1;
	philos[id].last_time_eaten = gettime();
	philos[id].right_fork = &pd->forks[id];
	philos[id].left_fork = &pd->forks[id - 1];
	philos[id].amount_meals_eaten = 0;
	if (id == 0)
		philos[id].left_fork = &pd->forks[pd->amount_philos - 1];
	if (pthread_mutex_init(&philos[id].amount_meals_lock, NULL) != 0)
		return (false);
	if (pthread_create(&pd->philo_threads[id], NULL, \
		run_philosopher, &philos[id]) != 0)
		return (false);
	return (true);
}

void	join_threads(uint32_t amount_philos, pthread_t *philo_threads)
{
	size_t	i;

	i = 0;
	while (i < amount_philos)
	{
		pthread_join(philo_threads[i], NULL);
		i++;
	}
}

bool	create_sim_death_checker(t_philosopher *philos)
{
	pthread_t	death_checker;

	if (pthread_create(&death_checker, NULL, run_death_checker, philos) != 0)
		return (false);
	pthread_join(death_checker, NULL);
	return (true);
}
