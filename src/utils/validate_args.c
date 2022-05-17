/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_args.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 09:40:18 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/17 22:21:12 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdint.h>	// uint32_t
#include <stdio.h>	// printf

/**
 * @brief 
 * Checks if a string is only comprised of charactes 
 * that are valid in the number spectrum [0-9] [- +]
 * 
 * @param str 
 * @return bool
 */
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

/**
 * @brief 
 * Takes in the command line arguments and checks if 
 * they are formatted correctly
 * @param argc 
 * @param argv 
 * @return bool
 */
bool	validate_arguments(uint32_t argc, char **argv)
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
		{
			printf("Error: a number was formatted incorrectly\n");
			return (false);
		}
		i++;
	}
	return (true);
}
