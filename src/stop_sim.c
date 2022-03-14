/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_sim.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 14:56:02 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/14 11:05:38 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Seperate thread for checking death of philo_threads
// It loops constantly checking if all the philo's are dead
// It also checks whether the philo's have eaten

#include "philo.h"
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>

void	print_death(t_program_data *pd, t_philosopher *philo)
{
	pthread_mutex_lock(&pd->print_lock);
	printf(RED "%li %i died\n" RESET, gettime() - pd->start_time, philo->id);
	pthread_mutex_unlock(&pd->print_lock);
}

void	set_stop_sim_lock(t_program_data *pd)
{
	pthread_mutex_lock(&pd->stop_sim_lock);
	pd->stop_sim = true;
	pthread_mutex_unlock(&pd->stop_sim_lock);
}

enum e_bool	is_philo_dead(t_philosopher *philo)
{
	t_program_data	*pd;
	int				time_to_die;

	pd = philo->pd;
	time_to_die = philo->pd->time_to_die;
	if ((gettime() - pd->start_time) - \
		(philo->last_time_eaten - pd->start_time) > time_to_die)
	{
		print_death(pd, philo);
		set_stop_sim_lock(pd);
		return (true);
	}
	return (false);
}

void	*run_death_checker(void *philos_array)
{
	t_philosopher	*philos;
	int				i;
	int				amount_philo;

	philos = (t_philosopher *)philos_array;
	amount_philo = philos[0].pd->amount_philo;
	while (1)
	{
		i = 0;
		while (i < amount_philo)
		{
			if (is_philo_dead(&philos[i]))
				return (NULL);
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
	free(philos);
}
