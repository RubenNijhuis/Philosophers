/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_threads.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 13:05:37 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/10 11:28:10 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_threads(t_program_data *pd)
{
	int	i;

	i = 0;
	while (i < pd->amount_philo)
	{
		pthread_join(pd->philo_threads[i], NULL);
		i++;
	}
}
