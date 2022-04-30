/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gettime.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 13:52:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/30 09:56:39 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>	// gettimeofday
#include <stdlib.h>		// uint32_t

uint32_t	gettime(void)
{
	uint32_t	ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}
