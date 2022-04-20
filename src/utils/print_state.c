/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 13:37:57 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/20 14:28:32 by rnijhuis      ########   odam.nl         */
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
		printf("%li %i ", cur_time, id);
		if (state == sleeping)
			printf(MAG "is sleeping\n" RESET);
		else if (state == eating)
			printf(GRN "is eating\n" RESET);
		else if (state == pick_up_fork)
			printf(YEL "has taken a fork\n" RESET);
		else if (state == thinking)
			printf(BLU "is thinking\n" RESET);
	}
	pthread_mutex_unlock(&philo->pd->print_lock);
}
