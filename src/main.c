/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:13:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/03 11:40:31 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>

/**
 * TODO: Maak extra thread die de doodheid van philos checkt
 * TODO: Tijd uitvogelen
 * TODO: 
 * 
 * 
 */

// initiate_death_checker(&program_data);

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
	sim_death_checker(&program_data);
	close_threads(&program_data);
	return (0);
}
