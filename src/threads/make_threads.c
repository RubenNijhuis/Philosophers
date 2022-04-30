/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_threads.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:58 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/30 09:54:07 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	make_philo_thread(t_philosopher *philos, t_program_data *pd, int id)
{
	philos[id].pd = pd;
	philos[id].id = id + 1;
	philos[id].last_time_eaten = gettime();
	philos[id].right_fork = id;
	philos[id].left_fork = id - 1;
	philos[id].amount_meals_eaten = 0;
	if (pthread_mutex_init(&philos[id].amount_meals_lock, NULL) != 0)
		return (false);
	if (id == 0)
		philos[id].left_fork = pd->amount_philo - 1;
	if (pthread_create(&pd->philo_threads[id], NULL, \
		run_philosopher, &philos[id]) != 0)
		return (false);
	return (true);
}

void	close_threads(t_program_data *pd)
{
	uint32_t	i;

	i = 0;
	while (i < pd->amount_philo)
	{
		pthread_join(pd->philo_threads[i], NULL);
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
