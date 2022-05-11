/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gettime.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 13:52:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/11 18:46:45 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>	// gettimeofday
#include <stdint.h>		// uint32_t

uint32_t	gettime(void)
{
	uint32_t		ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}
