/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initiate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 13:25:22 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/08 12:38:22 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Initiates the basic data that every philo needs
	and puts it into the program data struct
	Also initializes the mutexes for global use
*/
bool	initiate_data(t_program_data *pd, char **argv)
{
	pd->amount_philos = (uint32_t)ft_atoi(argv[1]);
	pd->time_to_die = (uint32_t)ft_atoi(argv[2]);
	pd->time_to_eat = (uint32_t)ft_atoi(argv[3]);
	pd->time_to_sleep = (uint32_t)ft_atoi(argv[4]);
	if (argv[5])
		pd->amount_meals = (uint32_t)ft_atoi(argv[5]);
	pd->start_time = gettime();
	pd->forks = ft_calloc(pd->amount_philos, sizeof(pthread_mutex_t));
	if (!pd->forks)
		return (false);
	pd->philo_threads = ft_calloc(pd->amount_philos, sizeof(pthread_t));
	if (!pd->philo_threads)
		return (false);
	if (pthread_mutex_init(&pd->print_lock, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&pd->stop_sim_lock, NULL) != 0)
		return (false);
	return (true);
}

/*
	Initiates the table bits, philosopher threads and forks
	As well as the death checker thread
*/
bool	initiate_table(t_program_data *pd, t_philosopher *philos)
{
	size_t	i;

	i = 0;
	while (i < pd->amount_philos)
	{
		if (pthread_mutex_init(&pd->forks[i], NULL) != 0)
			return (false);
		if (make_philo_thread(philos, pd, i) == false)
			return (false);
		i++;
	}
	if (!create_sim_death_checker(philos))
		return (false);
	return (true);
}
