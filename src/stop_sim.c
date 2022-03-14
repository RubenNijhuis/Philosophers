/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_sim.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 14:56:02 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/14 16:07:50 by rnijhuis      ########   odam.nl         */
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

enum e_bool	is_philo_dead(t_philosopher *philo, t_program_data *pd)
{
	pthread_mutex_lock(&philo->stop_sim_lock_local);
	if (philo->stop_sim == false)
	{
		if ((gettime() - pd->start_time) - \
			(philo->last_time_eaten - pd->start_time) > pd->time_to_die)
		{
			print_death(pd, philo);
			set_stop_sim_lock(pd);
			pthread_mutex_unlock(&philo->stop_sim_lock_local);
			return (true);
		}
	}
	pthread_mutex_unlock(&philo->stop_sim_lock_local);
	return (false);
}

enum e_bool	all_full(t_philosopher *philos, t_program_data *pd)
{
	int				i;
	int				amount_full;

	i = 0;
	amount_full = 0;
	while (i < pd->amount_philo)
	{
		pthread_mutex_lock(&philos[i].amount_meals_lock);
		if (philos[i].amount_meals_eaten == pd->amount_meals)
		{
			pthread_mutex_lock(&philos[i].stop_sim_lock_local);
			philos[i].stop_sim = true;
			pthread_mutex_unlock(&philos[i].stop_sim_lock_local);
			amount_full++;
		}
		pthread_mutex_unlock(&philos[i].amount_meals_lock);
		if (amount_full == pd->amount_philo)
		{
			set_stop_sim_lock(pd);
			return (true);
		}
		i++;
	}
	return (false);
}

void	*run_death_checker(void *philos_array)
{
	t_philosopher	*philos;
	t_program_data	*pd;
	int				i;

	philos = (t_philosopher *)philos_array;
	pd = philos[0].pd;
	while (1)
	{
		i = 0;
		while (i < pd->amount_philo)
		{
			if (is_philo_dead(&philos[i], pd))
				return (NULL);
			i++;
		}
		if (all_full(philos, pd))
			return (NULL);
	}
	return (NULL);
}
