/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:23:26 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/01/27 16:49:05 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>

typedef struct s_program_data
{
	int			amount_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			amount_meals;
	int			*forks;
	pthread_t	*philosophers;
}	t_program_data;

typedef struct s_philosopher
{
	int			start_time;
	int			id;
	int			times_eaten;
}	t_philoshoper;

// General utils
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *src);

// Thread utils
void	close_threads(t_program_data *pd);

// Main functions
void	initialize_table(t_program_data *pd, char **argv);

#endif