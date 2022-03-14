/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 13:37:57 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/14 10:31:58 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "colors.h"
#include <stdio.h>

void	print_state(t_philosopher *philo, enum e_state state)
{
	int			id;
	long int	cur_time;

	id = philo->id;
	pthread_mutex_lock(&philo->pd->print_lock);
	if (philo->pd->stop_sim == false)
	{
		cur_time = gettime() - philo->pd->start_time;
		if (state == sleeping)
			printf(MAG "%li %i is sleeping\n" RESET, cur_time, id);
		else if (state == eating)
			printf(GRN "%li %i is eating\n" RESET, cur_time, id);
		else if (state == pick_up_fork)
			printf(YEL "%li %i has taken a fork\n" RESET, cur_time, id);
		else if (state == thinking)
			printf(BLU "%li %i is thinking\n" RESET, cur_time, id);
	}
	pthread_mutex_unlock(&philo->pd->print_lock);
}
