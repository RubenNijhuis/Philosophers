/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:13:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/03 18:11:48 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_program_data	program_data;

	if (!validate_arguments(argc, argv))
	{
		printf("Number of arguments insufficient\n");
		return (1);
	}
	initiate_data(&program_data, argv);
	initiate_table(&program_data);
	close_threads(&program_data);
	return (0);
}
