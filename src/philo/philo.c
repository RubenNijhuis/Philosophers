/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 18:03:08 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/14 17:07:28 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

enum e_bool	stop_sim(t_philosopher *philo)
{
	t_program_data	*pd;

	pd = philo->pd;
	pthread_mutex_lock(&pd->stop_sim_lock);
	if (pd->stop_sim == true)
	{
		pthread_mutex_unlock(&pd->stop_sim_lock);
		return (true);
	}
	pthread_mutex_unlock(&pd->stop_sim_lock);
	pthread_mutex_lock(&philo->stop_sim_lock_local);
	if (philo->stop_sim == true)
	{
		pthread_mutex_unlock(&philo->stop_sim_lock_local);
		return (true);
	}
	pthread_mutex_unlock(&philo->stop_sim_lock_local);
	return (false);
}

void	*run_philosopher(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	if (philo->id % 1 == 0)
		usleep(philo->pd->time_to_eat);
	while (!stop_sim(philo))
	{
		if (action_eating(philo) == false)
			return (NULL);
		if (action_sleeping(philo) == false)
			return (NULL);
		action_thinking(philo);
	}
	return (NULL);
}
