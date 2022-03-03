/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initiate_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 08:49:44 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/03 18:28:10 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <sys/time.h>
#include <stdio.h>

void	initiate_data(t_program_data *pd, char **argv)
{
	pd->amount_philo = ft_atoi(argv[1]);
	pd->time_to_die = ft_atoi(argv[2]);
	pd->time_to_eat = ft_atoi(argv[3]);
	pd->time_to_sleep = ft_atoi(argv[4]);
}

void	initiate_table(t_program_data *pd)
{
	int	i;
	t_philosopher *philos;

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
