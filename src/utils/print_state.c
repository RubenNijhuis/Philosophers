/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 13:37:57 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/12 07:36:31 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "colors.h"

#include <stdio.h>	// printf
#include <stdint.h>	// uint32_t

void	print_state(t_philosopher *philo, t_state state)
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
			printf(MAG "is sleeping\n" RESET);
		else if (state == eating)
			printf(GRN "is eating\n" RESET);
		else if (state == pick_up_fork)
			printf(YEL "has taken a fork\n" RESET);
		else if (state == thinking)
			printf(CYN "is thinking\n" RESET);
		else if (state == died)
			printf(RED "died\n" RESET);
	}
	pthread_mutex_unlock(&philo->pd->print_lock);
}
