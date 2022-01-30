/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:13:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/01/30 11:13:40 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Custom .h
#include "../include/philo.h"

// Include
#include <stdio.h>

void	eat(t_philosopher *philo)
{
	
}

void	*run_philosopher(void *philosopher)
{
	t_philosopher *philo = (t_philosopher *)philosopher;
	printf("%i %i has started\n", philo->start_time, philo->id);	

	gettimeofday(&philo->program_data->tv, &philo->program_data->tz);
	philo->last_time_eaten = philo->program_data->tv.tv_usec;
	while (1)
	{
		if (philo->program_data->time_to_die > (philo->last_time_eaten - philo->start_time))
		{
			printf("st: %i, lte: %i, diff: %i", philo->start_time, philo->last_time_eaten, (philo->last_time_eaten - philo->start_time));
			gettimeofday(&philo->program_data->tv, &philo->program_data->tz);
			printf("%i %i has died\n", philo->program_data->tv.tv_usec, philo->id);
			return (NULL);
		}

		pthread_mutex_lock(&philo->program_data->lock);
		if (!philo->program_data->forks[philo->id] && !philo->program_data->forks[philo->id - 1])
		{
			philo->program_data->forks[philo->id] = 1;
			philo->program_data->forks[philo->id - 1] = 1;

			gettimeofday(&philo->program_data->tv, &philo->program_data->tz);
			philo->last_time_eaten = philo->program_data->tv.tv_usec;
			usleep(philo->program_data->time_to_eat * 1000);

			philo->program_data->forks[philo->id] = 0;
			philo->program_data->forks[philo->id - 1] = 0;
			printf("%i %i has eaten\n", philo->program_data->tv.tv_usec, philo->id);
		}
		pthread_mutex_unlock(&philo->program_data->lock);
		
	}
	return (NULL);
}

/**
• Each philosopher should be a thread.

• There is one fork between each pair of philosophers. Therefore, if there are several
  philosophers, each philosopher has a fork on their left side and a fork on their right
  side. If there is only one philosopher, there should be only one fork on the table.

• To prevent philosophers from duplicating forks, you should protect the forks state
  with a mutex for each of them.
*/

void	initiate_table(t_program_data *pd)
{
	int i;
	t_philosopher *philo;

	pthread_mutex_init(&pd->lock, NULL);
	pd->philosophers = ft_calloc(pd->amount_philo, sizeof(pthread_t));
	i = 0;
	while (i < pd->amount_philo)
	{
		philo = ft_calloc(1, sizeof(t_philosopher));
		philo->program_data = pd;
		gettimeofday(&pd->tv, &pd->tz);
		philo->start_time = pd->tv.tv_usec;
		philo->id = i + 1;
		pthread_create(&pd->philosophers[i], NULL, run_philosopher, philo);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program_data	program_data;

	if (!validate_arguments(argc, argv))
	{
		printf("Amount vars not ok\n");
		usleep(1250000);
		printf("\nidiot\n");
		return (1);
	}
	initiate_data(&program_data, argv);
	initiate_table(&program_data);
	for (int i = 0; i < program_data.amount_philo; i++)
		pthread_join(program_data.philosophers[i], NULL);
	return (0);
}
