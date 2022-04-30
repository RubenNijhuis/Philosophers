/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 13:37:57 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/30 09:58:27 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>	// printf
#include <stdlib.h> // uint32_t

void	print_state(t_philosopher *philo, enum e_state state)
{
	uint32_t	id;
	uint32_t	cur_time;

	id = philo->id;
	pthread_mutex_lock(&philo->pd->print_lock);
	if (stop_sim(philo) == false)
	{
		cur_time = gettime() - philo->pd->start_time;
		printf("%011u %u ", cur_time, id);
		if (state == sleeping)
			printf("is sleeping\n");
		else if (state == eating)
			printf("is eating\n");
		else if (state == pick_up_fork)
			printf("has taken a fork\n");
		else if (state == thinking)
			printf("is thinking\n");
		else if (state == died)
			printf("died\n");
	}
	pthread_mutex_unlock(&philo->pd->print_lock);
}
