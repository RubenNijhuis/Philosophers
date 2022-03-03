/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_philo_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:58 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/03 10:16:31 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <pthread.h>
#include <unistd.h>

void	make_fork(t_program_data *pd, int id)
{
	pthread_mutex_init(&pd->forks[id], NULL);
}

void	make_philo_thread(t_philosopher *philos, t_program_data *pd, int id)
{
	t_philosopher	*philo;

	philo = ft_calloc(1, sizeof(t_philosopher));
	philo->pd = pd;
	philo->id = id + 1;
	philo->start_time = gettime(philo->pd->tv);
	philo->right_fork = id;
	if (id == 0)
		philo->left_fork = pd->amount_philo - 1;
	else
		philo->left_fork = id - 1;
	philos[id] = *philo;
	pthread_create(&pd->philo_threads[id], NULL, run_philosopher, philo);
	// return (philo);
}
