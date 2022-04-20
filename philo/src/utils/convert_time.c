/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_time.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 13:52:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/12 10:13:03 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	gettime(void)
{
	long			ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}
