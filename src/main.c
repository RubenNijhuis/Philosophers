/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:13:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/02/28 14:27:08 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Custom .h
#include "../include/philo.h"

// Include
#include <stdio.h>

enum Bool	eat(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->pd->forks[philo->left_fork]);
		printf("%i picked up left fork\n", philo->id);
		pthread_mutex_lock(&philo->pd->forks[philo->right_fork]);
		printf("%i picked up right fork\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->pd->forks[philo->right_fork]);
		printf("%i picked up right fork\n", philo->id);
		pthread_mutex_lock(&philo->pd->forks[philo->left_fork]);
		printf("%i picked up left fork\n", philo->id);
	}
	printf("%i %i is eating\n", philo->philo->id);
	usleep(philo->pd->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->pd->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->pd->forks[philo->right_fork]);
	return (TRUE);
}

void	*run_philosopher(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	gettimeofday(&philo->pd->tv, &philo->pd->tz);
	philo->last_time_eaten = philo->pd->tv.tv_usec / 1000 + philo->pd->tv.tv_sec * 1000;
	while (1)
	{
		usleep(750000);
		eat(philo);
		gettimeofday(&philo->pd->tv, &philo->pd->tz);
		philo->last_time_eaten = philo->pd->tv.tv_usec / 1000 + philo->pd->tv.tv_sec * 1000;
		printf("%i is sleeping\n", philo->id);
		usleep(philo->pd->time_to_sleep * 1000);
		printf("%i philo is thinking\n", philo->id);
	}
	return (NULL);
}

void	initiate_table(t_program_data *pd)
{
	int	i;

	gettimeofday(&pd->tv, &pd->tz);
	i = 0;
	while (i < pd->amount_philo)
	{
		make_forks(pd, i);
		make_threads(pd, i);
		i++;
	}
}

/**
 * TODO: Maak extra thread die de doodheid van philos checkt
 * TODO: Tijd uitvogelen
 * TODO: 
 * 
 * 
 */

int	main(int argc, char **argv)
{
	t_program_data	program_data;

	if (!validate_arguments(argc, argv))
	{
		printf("Number of arguments insufficient\n");
		return (1);
	}
	initiate_data(&program_data, argv);
	initiate_table(&program_data);
	// initiate_death_checker(&program_data);
	close_threads(&program_data);
	return (0);
}
