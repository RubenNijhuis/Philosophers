/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initiate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 13:25:22 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/25 18:10:23 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Initiates the basic data that every philo needs
	and puts it into the program data struct
	Also initializes the mutexes for global use
 */
int	initiate_data(t_program_data *pd, char **argv)
{
	pd->amount_philo = ft_atoi(argv[1]);
	pd->time_to_die = ft_atoi(argv[2]);
	pd->time_to_eat = ft_atoi(argv[3]);
	pd->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		pd->amount_meals = ft_atoi(argv[5]);
	pd->start_time = gettime();
	if (pthread_mutex_init(&pd->print_lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&pd->stop_sim_lock, NULL) != 0)
		return (0);
	return (1);
}

/*
	Initiates the table bits, philosopher threads and forks
	As well as the death checker thread
 */
int	initiate_table(t_program_data *pd, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < pd->amount_philo)
	{
		if (pthread_mutex_init(&pd->forks[i], NULL) != 0)
			return (0);
		if (!make_philo_thread(philos, pd, i))
			return (0);
		i++;
	}
	if (!create_sim_death_checker(philos))
		return (0);
	return (1);
}
