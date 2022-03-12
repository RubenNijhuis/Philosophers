/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_sim.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 14:56:02 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/12 10:10:28 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Seperate thread for checking death of philo_threads
// It loops constantly checking if all the philo's are dead
// It also checks whether the philo's have eaten

#include "philo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

enum e_bool	is_philo_dead(t_philosopher *philo)
{
	t_program_data	*pd;
	int				time_to_die;

	pd = philo->pd;
	time_to_die = philo->pd->time_to_die;
	if (((gettime() - pd->start_time) - (philo->last_time_eaten - pd->start_time)) \
		> time_to_die)
	{
		pthread_mutex_lock(&pd->stop_sim_lock);
		pd->stop_sim = true;
		pthread_mutex_unlock(&pd->stop_sim_lock);
		pthread_mutex_lock(&pd->print_lock);
		printf("%li %i died - lte: %li // tod: %li -- dif: %li\n", \
			gettime() - pd->start_time, \
			philo->id, \
			philo->last_time_eaten - pd->start_time, \
			gettime() - pd->start_time, \
			gettime() - philo->last_time_eaten - pd->time_to_die
		);
		pthread_mutex_unlock(&pd->print_lock);
		return (true);
	}
	return (false);
}

void	*run_death_checker(void *philos_array)
{
	t_philosopher	*philos;
	int	i;

	philos = (t_philosopher *)philos_array;
	while (1)
	{
		i = 0;
		while (i < philos[0].pd->amount_philo)
		{
			if (is_philo_dead(&philos[i]) == true)
			{
				free(philos);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void	sim_death_checker(t_philosopher *philos)
{
	pthread_t	death_checker;

	pthread_create(&death_checker, NULL, run_death_checker, philos);
	pthread_join(death_checker, NULL);
}
