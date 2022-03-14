/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 18:03:08 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/14 11:15:57 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_bool	stop_sim(t_program_data *pd)
{
	pthread_mutex_lock(&pd->stop_sim_lock);
	if (pd->stop_sim == true)
	{
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
	while (!stop_sim(philo->pd))
	{
		action_eating(philo);
		action_sleeping(philo);
		action_thinking(philo);
	}
	return (NULL);
}
