/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:13:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/25 18:12:22 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Start of the program due to the limit of
	not being able to use `exit()` I had to add
	a lot of return checks
 */
int	main(int argc, char **argv)
{
	t_program_data	pd;
	t_philosopher	*philos;

	philos = NULL;
	ft_bzero(&pd, sizeof(pd));
	if (!validate_arguments(argc, argv))
		return (1);
	if (!initiate_data(&pd, argv))
		return (destroy_mutexes(philos, pd.stop_sim_lock, pd.print_lock));
	philos = ft_calloc(pd.amount_philo, sizeof(t_philosopher));
	if (!philos)
		return (destroy_mutexes(philos, pd.stop_sim_lock, pd.print_lock));
	if (!initiate_table(&pd, philos))
		return (destroy_mutexes(philos, pd.stop_sim_lock, pd.print_lock));
	close_threads(&pd);
	return (0);
}
