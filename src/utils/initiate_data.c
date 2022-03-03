/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initiate_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 08:49:44 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/03/03 10:17:00 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	initiate_data(t_program_data *pd, char **argv)
{
	struct timeval	tv;

	pd->tv = &tv;
	pd->amount_philo = ft_atoi(argv[1]);
	pd->time_to_die = ft_atoi(argv[2]);
	pd->time_to_eat = ft_atoi(argv[3]);
	pd->time_to_sleep = ft_atoi(argv[4]);
}

void	initiate_table(t_program_data *pd)
{
	int	i;

	i = 0;
	while (i < pd->amount_philo)
	{
		make_fork(pd, i);
		make_philo_thread(pd, i);
		i++;
	}
}
