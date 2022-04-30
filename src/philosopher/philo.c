/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 18:03:08 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/30 10:04:00 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h> // usleep

bool	stop_sim(t_philosopher *philo)
{
	t_program_data	*pd;

	pd = philo->pd;
	pthread_mutex_lock(&pd->stop_sim_lock);
	if (pd->stop_sim == true)
	{
		pthread_mutex_unlock(&pd->forks[philo->left_fork]);
		pthread_mutex_unlock(&pd->forks[philo->right_fork]);
		pthread_mutex_unlock(&pd->stop_sim_lock);
		return (true);
	}
	pthread_mutex_unlock(&pd->stop_sim_lock);
	return (false);
}

void	*run_philosopher(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	if (philo->pd->amount_philo == 1)
	{
		print_state(philo, pick_up_fork);
		usleep(philo->pd->time_to_die);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(50);
	while (stop_sim(philo) == false)
	{
		if (action_eating(philo) == false)
			return (NULL);
		if (action_sleeping(philo) == false)
			return (NULL);
		if (action_thinking(philo) == false)
			return (NULL);
	}
	return (NULL);
}
