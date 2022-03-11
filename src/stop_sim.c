/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_sim.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 14:56:02 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/10 14:22:14 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Seperate thread for checking death of philo_threads
// It loops constantly checking if all the philo's are dead
// It also checks whether the philo's have eaten

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	*run_death_checker(void *philos_array)
{
	t_philosopher	*philos;
	int				cur_philo_id;
	long			time_to_die;
	t_philosopher	cur_philo;

	philos = (t_philosopher *)philos_array;
	time_to_die = philos[0].pd->time_to_die;
	while (1)
	{
		cur_philo_id = 0;
		cur_philo = philos[cur_philo_id];
		while (cur_philo_id < cur_philo.pd->amount_philo)
		{
			if ((gettime() - cur_philo.last_time_eaten) > time_to_die)
			{
				cur_philo.pd->stop_sim = true;
				pthread_mutex_lock(&cur_philo.pd->print_lock);
				printf("%li %i died\n", gettime(), cur_philo.id);
				pthread_mutex_unlock(&cur_philo.pd->print_lock);
				return (NULL);
			}
			cur_philo_id++;
		}
	}
	return (NULL);
}

void	sim_death_checker(t_philosopher *philos)
{
	pthread_t	death_checker;

	usleep(1 * 1000);
	pthread_create(&death_checker, NULL, run_death_checker, philos);
	pthread_join(death_checker, NULL);
}