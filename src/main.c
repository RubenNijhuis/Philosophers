/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:13:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/02/23 16:28:43 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Custom .h
#include "../include/philo.h"

// Include
#include <stdio.h>

// void	eat(t_philosopher *philo)
// {

// }

// void pick_up_forks(t_philosopher *philo)
// {

// }

// int		check_forks(t_program_data *pd, int left_fork, int right_fork);
// {
// 	// Links
// 	pthread_mutex_lock(&philo->pd->forks[philo->left_fork]);
// 	printf("%i picked up left fork\n", philo->id);
// 	// Rechts
// 	pthread_mutex_lock(&philo->pd->forks[philo->right_fork]);
// 	printf("%i picked up right fork\n", philo->id);
// }

void	*run_philosopher(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	gettimeofday(&philo->pd->tv, &philo->pd->tz);
	philo->last_time_eaten = philo->pd->tv.tv_usec / 1000;
	while (1)
	{
		usleep(100000);
		check_forks(philo->program_data)
			printf("%i is eating\n", philo->id);
		usleep(philo->pd->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->pd->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->pd->forks[philo->id]);
		printf("%i is sleeping\n", philo->id);
		usleep(philo->pd->time_to_sleep * 1000);
		printf("%i philo is thinking\n", philo->id);
	}
	return (NULL);
}

/**
• Each philosopher should be a thread.

• There is one fork between each pair of philosophers. Therefore,
	if there are several
  philosophers,
	each philosopher has a fork on their left side and a fork on their right
  side. If there is only one philosopher,
	there should be only one fork on the table.

• To prevent philosophers from duplicating forks,
	you should protect the forks state
  with a mutex for each of them.
*/

void	initiate_table(t_program_data *pd)
{
	int				i;
	t_philosopher	*philo;

	gettimeofday(&pd->tv, &pd->tz);
	i = 0;
	while (i < pd->amount_philo)
	{
		pthread_mutex_init(&pd->forks[i], NULL);
		philo = ft_calloc(1, sizeof(t_philosopher));
		philo->pd = pd;
		philo->start_time = pd->tv.tv_usec / 1000;
		philo->id = i + 1;
		if (i == 0)
		{
			philo->left_fork = pd->amount_philo - 1;
			philo->right_fork = 0;
		}
		else if (i == pd->amount_philo - 1)
		{
			philo->left_fork = i - 1;
			philo->right_fork = pd->amount_philo - 1;
		}
		else
		{
			philo->left_fork = i - 1;
			philo->right_fork = i;
		}
		printf("%i lf: %i -- rf: %i\n", philo->id, philo->left_fork,
				philo->right_fork);
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
