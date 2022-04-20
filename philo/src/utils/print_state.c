/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 13:37:57 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/20 17:19:54 by rnijhuis      ########   odam.nl         */
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
		cur_time = gettime() - philo->pd->start_time + 00000000001;
		printf("%011li %i ", cur_time, id);
		if (state == sleeping)
			printf("is sleeping\n");
		else if (state == eating)
			printf("is eating\n");
		else if (state == pick_up_fork)
			printf("has taken a fork\n");
		else if (state == thinking)
			printf("is thinking\n");
	}
	pthread_mutex_unlock(&philo->pd->print_lock);
}
