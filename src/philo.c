/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 18:03:08 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/03 11:23:23 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>
#include <unistd.h>

enum e_Bool	eat(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->pd->forks[philo->left_fork]);
		printf("%li %i has taken a fork\n", gettime(philo->pd->tv), philo->id);
		pthread_mutex_lock(&philo->pd->forks[philo->right_fork]);
		printf("%li %i has taken a fork\n", gettime(philo->pd->tv), philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->pd->forks[philo->right_fork]);
		printf("%li %i has taken a fork\n", gettime(philo->pd->tv), philo->id);
		pthread_mutex_lock(&philo->pd->forks[philo->left_fork]);
		printf("%li %i has taken a fork\n", gettime(philo->pd->tv), philo->id);
	}
	printf("%li %i is eating\n", gettime(philo->pd->tv), philo->id);
	usleep(philo->pd->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->pd->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->pd->forks[philo->right_fork]);
	return (true);
}

void	*run_philosopher(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	while (1)
	{
		usleep(50000);
		eat(philo);
		printf("%li %i is sleeping\n", gettime(philo->pd->tv), philo->id);
		usleep(philo->pd->time_to_sleep * 1000);
		printf("%li %i is thinking\n", gettime(philo->pd->tv), philo->id);
	}
	return (NULL);
}
