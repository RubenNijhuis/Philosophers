/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:13:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/25 10:30:13 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_program_data	program_data;

	if (!validate_arguments(argc, argv))
	{
		printf("Arguments formatted incorrectly\n");
		return (1);
	}
	initiate_data(&program_data, argv);
	initiate_table(&program_data);
	close_threads(&program_data);
	return (0);
}
