/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:13:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/01/27 17:05:57 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Custom .h
#include <philo.h>

// Include
#include <stdio.h>
#include <pthread.h>

/**
• Each philosopher should be a thread.

• There is one fork between each pair of philosophers. Therefore, if there are several
  philosophers, each philosopher has a fork on their left side and a fork on their right
  side. If there is only one philosopher, there should be only one fork on the table.

• To prevent philosophers from duplicating forks, you should protect the forks state
  with a mutex for each of them.
*/

void	*test_thread_func(void *vargp)
{
	(void)vargp;
	sleep(1);
	printf("Je moeder %s \n");
	return (NULL);
}

void	initiate_table(t_program_data *pd, char **argv)
{
	pd->philosophers
	pthread_create(&thread_id, NULL, test_thread_func, NULL);
}

int	main(int argc, char **argv)
{
	t_program_data	program_data;
	pthread_t		thread_id;

	if (!validate_arguments(argc, argv))
	{
		printf("Amount vars not ok\n");
		usleep(1250000);
		printf("\nidiot\n");
		return (1);
	}
	initiate_table(&program_data, argv);
	pthread_create(&thread_id, NULL, test_thread_func, NULL);
	pthread_join(thread_id, NULL);
	return (0);
}
