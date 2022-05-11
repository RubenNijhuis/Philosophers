/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:13:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/11 18:43:15 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

/*
	Start of the program due to the limit of
	not being able to use `exit()` I had to add
	a lot of return checks
 */
int32_t	main(int argc, char **argv)
{
	t_program_data	pd;
	t_philosopher	*philos;

	philos = NULL;
	ft_bzero(&pd, sizeof(t_program_data));
	if (validate_arguments(argc, argv) == false)
		return (EXIT_FAILURE);
	if (initiate_data(&pd, argv) == false)
		return (destroy_mutexes(philos, pd.stop_sim_lock, pd.print_lock));
	philos = ft_calloc(pd.amount_philo, sizeof(t_philosopher));
	if (!philos)
		return (destroy_mutexes(philos, pd.stop_sim_lock, pd.print_lock));
	if (initiate_table(&pd, philos) == false)
		return (destroy_mutexes(philos, pd.stop_sim_lock, pd.print_lock));
	close_threads(&pd);
	destroy_mutexes(philos, pd.stop_sim_lock, pd.print_lock);
	return (EXIT_SUCCESS);
}
