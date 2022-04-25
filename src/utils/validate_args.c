/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_only_number.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 09:40:18 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/25 18:02:03 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static enum e_bool	is_only_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

enum e_bool	validate_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (false);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 1 || is_only_number(argv[1]) == false)
			return (false);
		i++;
	}
	return (true);
}
