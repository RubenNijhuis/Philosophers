/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_threads.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:37 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/01/27 13:17:55 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/**
 * @brief 
 * 
 * Small function to close all threads, probably only used if
 * program takes an "amount_meals" argument
 * @param pd (t_program_data)
 */
void	close_threads(t_program_data *pd)
{
	int	i;

	i = 0;
	while (i < pd->amount_philo)
	{
		pthread_join(pd->philosophers[i], NULL);
		i++;
	}
}
