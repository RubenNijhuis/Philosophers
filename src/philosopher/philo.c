/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 18:03:08 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/16 12:33:07 by rubennijhui   ########   odam.nl         */
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
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&pd->stop_sim_lock);
		return (true);
	}
	pthread_mutex_unlock(&pd->stop_sim_lock);
	return (false);
}

void	increment_amount_times_eaten(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->amount_meals_lock);
	philo->amount_meals_eaten++;
	pthread_mutex_unlock(&philo->amount_meals_lock);
}

static void	*single_philo_case(t_philosopher *philo)
{
	print_state(philo, pick_up_fork);
	usleep(philo->pd->time_to_die);
	return (NULL);
}

void	*run_philosopher(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	if (philo->pd->amount_philo == 1)
		return (single_philo_case(philo));
	if (philo->id % 2 == 0)
		usleep(ACTION_INTERVAL);
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
