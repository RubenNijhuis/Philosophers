/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   death_checker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 14:56:02 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/17 22:18:26 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>	// usleep
#include <stdint.h>	// uint32_t

static void	set_stop_sim_lock(t_program_data *pd)
{
	pthread_mutex_lock(&pd->stop_sim_lock);
	pd->stop_sim = true;
	pthread_mutex_unlock(&pd->stop_sim_lock);
}

static bool	is_philo_dead(t_philosopher *philo, t_program_data *pd)
{
	if ((gettime() - philo->last_time_eaten) > pd->time_to_die)
	{
		print_state(philo, died);
		set_stop_sim_lock(pd);
		return (true);
	}
	return (false);
}

static bool	all_full(t_philosopher *philos, t_program_data *pd)
{
	uint32_t	i;
	uint32_t	amount_full;

	i = 0;
	amount_full = 0;
	while (i < pd->amount_philos)
	{
		pthread_mutex_lock(&philos[i].amount_meals_lock);
		if (philos[i].amount_meals_eaten == pd->amount_meals)
			amount_full++;
		pthread_mutex_unlock(&philos[i].amount_meals_lock);
		if (amount_full == pd->amount_philos)
		{
			set_stop_sim_lock(pd);
			return (true);
		}
		i++;
	}
	return (false);
}

/**
 * @brief 
 * Seperate thread that checks the status of the philos.
 * Will return null if a philsopher died or if they 
 * have eaten a specified number of times
 * 
 * @param philos_array 
 * @return void* 
 */
void	*run_death_checker(void *philos_array)
{
	t_philosopher	*philos;
	t_program_data	*pd;
	uint32_t		i;

	philos = (t_philosopher *)philos_array;
	pd = philos[0].pd;
	while (1)
	{
		i = 0;
		while (i < pd->amount_philos)
		{
			if (is_philo_dead(&philos[i], pd) == true)
				return (NULL);
			i++;
		}
		if (pd->amount_meals > 0 && all_full(philos, pd) == true)
			return (NULL);
		usleep(CHECKER_INTERVAL);
	}
	return (NULL);
}
