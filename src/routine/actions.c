/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher_actions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 14:35:58 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/08 12:37:42 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <stdint.h>

static bool	start_action(t_philosopher *philo, t_state state, uint32_t duration)
{
	int64_t	start_time;

	start_time = gettime();
	print_state(philo, state);
	while (gettime() - start_time < duration)
	{
		if (stop_sim(philo) == true)
			return (false);
		usleep(ACTION_INTERVAL);
	}
	return (true);
}

/*
 * Subfunction or philo
 * will sleep for the specified time
 */
bool	action_sleeping(t_philosopher *philo)
{
	if (start_action(philo, sleeping, philo->pd->time_to_sleep) == false)
		return (false);
	return (true);
}

/*
 * Subfunction for philo
 * will think for a bit and move on
 */
bool	action_thinking(t_philosopher *philo)
{
	if (start_action(philo, thinking, 0) == false)
		return (false);
	return (true);
}

/*
 * Subfunction for philo
 * uses the mutexes to claim forks
 */
static void	pick_up_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, pick_up_fork);
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, pick_up_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, pick_up_fork);
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, pick_up_fork);
	}
}

/*
 * Philo will pick up their forks and eat
 * records: last_time_eaten
 */
bool	action_eating(t_philosopher *philo)
{
	pick_up_forks(philo);
	philo->last_time_eaten = gettime();
	if (philo->pd->amount_meals > 0)
		increment_amount_times_eaten(philo);
	if (start_action(philo, eating, philo->pd->time_to_eat) == false)
		return (false);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (true);
}
