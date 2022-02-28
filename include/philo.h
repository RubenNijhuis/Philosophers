/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:23:26 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/02/28 14:18:23 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

enum Bool { FALSE, TRUE };

typedef struct s_program_data
{
	int				amount_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				amount_meals;
	pthread_mutex_t	forks[200];
	int				forks_available[200];
	struct timezone	tz;
	struct timeval	tv;
	pthread_t		philosophers[200];
}	t_program_data;

typedef struct s_philosopher
{
	long			start_time;
	int				id;
	long			last_time_eaten;
	int				times_eaten;
	int				left_fork;
	int				right_fork;
	t_program_data	*pd;
}	t_philosopher;

// General utils
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *src);
int		validate_arguments(int argc, char **argv);
void	initiate_data(t_program_data *pd, char **argv);
void	*run_philosopher(void *philosopher);

void	make_threads(t_program_data *pd, int id);
void	make_forks(t_program_data *pd, int id);

// Thread utils
void	close_threads(t_program_data *pd);

// Main functions
void	initialize_table(t_program_data *pd);

#endif