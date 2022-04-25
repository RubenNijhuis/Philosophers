/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_arguments.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 20:03:05 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/25 15:55:24 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_bool	validate_arguments(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (false);
	if (argv[5] && ft_atoi(argv[5]) < 1)
		return (false);
	if (ft_atoi(argv[1]) < 1)
		return (false);
	if (is_only_number(argv[1]) == false)
		return (false);
	if (is_only_number(argv[2]) == false)
		return (false);
	if (is_only_number(argv[3]) == false)
		return (false);
	if (is_only_number(argv[4]) == false)
		return (false);
	return (true);
}
