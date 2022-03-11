/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   states.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 14:35:58 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/11 16:22:01 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	start_sleeping(t_philosopher *philo)
{
	print_state(philo, sleeping);
	usleep(philo->pd->time_to_sleep * 1000);
}

void	start_thinking(t_philosopher *philo)
{
	print_state(philo, thinking);
}

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

void	start_eating(t_philosopher *philo)
{
	int	times_waited;

	times_waited = 0;
	pick_up_forks(philo);
	print_state(philo, eating);
	while (1)
	{
		if (times_waited * 1000 >= philo->pd->time_to_eat * 1000)
			break ;
		if (stop_sim(philo->pd) == true)
			break ;
		times_waited++;
		usleep(1000);
	}
	philo->last_time_eaten = gettime();
	pthread_mutex_unlock(&philo->pd->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->pd->forks[philo->right_fork]);
}
