/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_time.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 13:52:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/11 18:07:29 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

long	gettime(void)
{
	long			ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}
