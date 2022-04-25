/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_threads.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:58 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/25 16:22:10 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>


int	make_philo_thread(t_philosopher *philos, t_program_data *pd, int id)
{
	philos[id].pd = pd;
	philos[id].id = id + 1;
	philos[id].last_time_eaten = gettime();
	philos[id].right_fork = id;
	philos[id].left_fork = id - 1;
	philos[id].amount_meals_eaten = 0;
	if (pthread_mutex_init(&philos[id].amount_meals_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&philos[id].stop_sim_lock_local, NULL) != 0)
		return (0);
	if (id == 0)
		philos[id].left_fork = pd->amount_philo - 1;
	if (pthread_create(&pd->philo_threads[id], NULL, run_philosopher, &philos[id]) != 0)
		return (0);
	return (1);
}

int	create_sim_death_checker(t_philosopher *philos)
{
	pthread_t	death_checker;

	if (pthread_create(&death_checker, NULL, run_death_checker, philos) != 0)
		return (0);
	pthread_join(death_checker, NULL);
	return (1);
}
