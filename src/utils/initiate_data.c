/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initiate_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 08:49:44 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/02/23 13:56:45 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void initiate_data(t_program_data *pd, char **argv)
{
	int amount_philo = ft_atoi(argv[1]);
	int time_to_die = ft_atoi(argv[2]);
	int time_to_eat = ft_atoi(argv[3]);
	int time_to_sleep = ft_atoi(argv[4]);

	pd->amount_philo = amount_philo;
	pd->time_to_die = time_to_die;
	pd->time_to_eat = time_to_eat;
	pd->time_to_sleep = time_to_sleep;
}