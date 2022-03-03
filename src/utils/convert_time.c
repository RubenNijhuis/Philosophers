/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_time.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 13:52:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/03 18:48:27 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

long	gettime()
{
	long	ms;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

void	usleep_optimized(int ms)
{
	int	wait_times;
	int	current_time;

	wait_times = ms % 10;
	current_time = 0;
	while (current_time < wait_times)
	{
		usleep(1000);
		current_time++;
	}
}
