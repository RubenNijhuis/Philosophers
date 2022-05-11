/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_args.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 09:40:18 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/11 18:45:26 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdint.h>	// uint32_t
#include <stdio.h>	// printf

static bool	is_only_number(char *str)
{
	uint32_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	validate_arguments(int argc, char **argv)
{
	uint32_t	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (false);
	if (ft_atoi(argv[1]) > 200)
	{
		printf("Error: too many philosophers\n");
		return (false);
	}
	while (i < (uint32_t)argc)
	{
		if (ft_atoi(argv[i]) < 1 || is_only_number(argv[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
