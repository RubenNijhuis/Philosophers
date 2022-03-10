/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initiate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 13:25:22 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/10 14:27:06 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

void	initiate_data(t_program_data *pd, char **argv)
{
	pd->amount_philo = ft_atoi(argv[1]);
	pd->time_to_die = ft_atoi(argv[2]);
	pd->time_to_eat = ft_atoi(argv[3]);
	pd->time_to_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&pd->print_lock, NULL);
	pthread_mutex_init(&pd->stop_sim_lock, NULL);
}

void	initiate_table(t_program_data *pd)
{
	int				i;
	t_philosopher	*philos;

	i = 0;
	philos = ft_calloc(pd->amount_philo, sizeof(t_philosopher));
	while (i < pd->amount_philo)
	{
		make_fork(pd, i);
		make_philo_thread(philos, pd, i);
		i++;
	}
	sim_death_checker(philos);
}
