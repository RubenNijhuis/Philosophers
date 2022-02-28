/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_threads.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:58 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/02/28 14:19:57 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	make_forks(t_program_data *pd, int id)
{
	pthread_mutex_init(&pd->forks[id], NULL);
}

void	make_threads(t_program_data *pd, int id)
{
	t_philosopher	*philo;

	philo = ft_calloc(1, sizeof(t_philosopher));
	philo->pd = pd;
	philo->start_time = philo->pd->tv.tv_usec / 1000 + philo->pd->tv.tv_sec * 1000;
	philo->id = id + 1;
	philo->right_fork = id;
	if (id == 0)
		philo->left_fork = pd->amount_philo - 1;
	else
		philo->left_fork = id - 1;
	pthread_create(&pd->philosophers[id], NULL, run_philosopher, philo);
}
