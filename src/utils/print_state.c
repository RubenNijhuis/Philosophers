/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 13:37:57 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/10 14:18:38 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	print_state(t_philosopher *philo, enum e_state state)
{
	int			id;
	long int	cur_time;

	id = philo->id;
	pthread_mutex_lock(&philo->pd->print_lock);
	if (philo->pd->stop_sim == false)
	{
		cur_time = gettime();
		if (state == sleeping)
			printf("%li %i is sleeping\n", cur_time, id);
		if (state == eating)
			printf("%li %i is eating\n", cur_time, id);
		if (state == pick_up_fork)
			printf("%li %i picked up a fork\n", cur_time, id);
		if (state == died)
			printf("%li %i died\n", cur_time, id);
		if (state == thinking)
			printf("%li %i thinking\n", cur_time, id);
	}
	pthread_mutex_unlock(&philo->pd->print_lock);
}
