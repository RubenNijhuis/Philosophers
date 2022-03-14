/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_threads.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:58 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/14 10:13:10 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	make_fork(t_program_data *pd, int id)
{
	pthread_mutex_init(&pd->forks[id], NULL);
}

void	make_philo_thread(t_philosopher *philos, t_program_data *pd, int id)
{
	philos[id].pd = pd;
	philos[id].id = id + 1;
	philos[id].last_time_eaten = gettime();
	philos[id].right_fork = id;
	philos[id].left_fork = id - 1;
	if (id == 0)
		philos[id].left_fork = pd->amount_philo - 1;
	pthread_create(&pd->philo_threads[id], NULL, run_philosopher, &philos[id]);
}
