/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   death_checker.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 14:56:02 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/07/08 12:34:51 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

static void	set_stop_sim_lock(t_program_data *pd)
{
	pthread_mutex_lock(&pd->stop_sim_lock);
	pd->stop_sim = true;
	pthread_mutex_unlock(&pd->stop_sim_lock);
}

static bool	is_philo_dead(t_philosopher *philo, t_program_data *pd)
{
	size_t	i;

	i = 0;
	while (i < pd->amount_philos)
	{
		if ((gettime() - philo[i].last_time_eaten) > pd->time_to_die)
		{
			print_state(&philo[i], died);
			set_stop_sim_lock(pd);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	all_full(t_philosopher *philos, t_program_data *pd)
{
	size_t		i;
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

	philos = (t_philosopher *)philos_array;
	pd = philos[0].pd;
	while (true)
	{
		if (is_philo_dead(philos, pd) == true)
			return (NULL);
		if (pd->amount_meals > 0 && all_full(philos, pd) == true)
			return (NULL);
		usleep(CHECKER_INTERVAL);
	}
	return (NULL);
}
