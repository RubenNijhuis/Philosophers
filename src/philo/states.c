/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   states.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 14:35:58 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/12 09:31:17 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	start_action(t_philosopher *philo, int duration)
{
	long	start_time;

	start_time = gettime();
	while (gettime() - start_time < duration)
	{
		if (stop_sim(philo->pd) == true)
			break ;
	}
}

/*
 * Subfunctionf or philo
 * will sleep for the specified time
*/
void	action_sleeping(t_philosopher *philo)
{
	print_state(philo, sleeping);
	start_action(philo, philo->pd->time_to_sleep);
}

/*
 * Subfunction for philo
 * will think for a bit and move on
*/
void	action_thinking(t_philosopher *philo)
{
	print_state(philo, thinking);
}

/*
 * Subfunction for philo
 * uses the mutexes to claim forks
*/
void	pick_up_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->pd->forks[philo->left_fork]);
		print_state(philo, pick_up_fork);
		pthread_mutex_lock(&philo->pd->forks[philo->right_fork]);
		print_state(philo, pick_up_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->pd->forks[philo->right_fork]);
		print_state(philo, pick_up_fork);
		pthread_mutex_lock(&philo->pd->forks[philo->left_fork]);
		print_state(philo, pick_up_fork);
	}
}

/*
 * Philo will pick up their forks and eat
 * records: last_time_eaten
*/
void	action_eating(t_philosopher *philo)
{
	pick_up_forks(philo);
	print_state(philo, eating);
	start_action(philo, philo->pd->time_to_eat);
	philo->last_time_eaten = gettime();
	pthread_mutex_unlock(&philo->pd->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->pd->forks[philo->right_fork]);
}
