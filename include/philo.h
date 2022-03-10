/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:23:26 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/03/10 14:50:16 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Required for struct definitions
# include <pthread.h>

// Enums
enum e_bool { false, true };
enum e_state { sleeping, eating, pick_up_fork, died, thinking };

// Program data
typedef struct s_program_data
{
	int				amount_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				amount_meals;
	enum e_bool		stop_sim;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_sim_lock;
	pthread_mutex_t	forks[200];
	pthread_t		philo_threads[200];
}	t_program_data;

// Philo struct
typedef struct s_philosopher
{
	int				id;
	long			start_time;
	long			last_time_eaten;
	int				times_eaten;
	int				left_fork;
	int				right_fork;
	t_program_data	*pd;
}	t_philosopher;

// Data inits
void			initiate_data(t_program_data *pd, char **argv);
void			initiate_table(t_program_data *pd);

// General utils
void			print_state(t_philosopher *philo, enum e_state state);

// Operational Utils
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *src);
int				validate_arguments(int argc, char **argv);
void			*run_philosopher(void *philosopher);
long int		gettime(void);
void			usleep_optimized(int ms);

// Philo states
void			start_eating(t_philosopher *philo);
void			start_sleeping(t_philosopher *philo);
void			start_thinking(t_philosopher *philo);

// Thread utils
void			close_threads(t_program_data *pd);
void			make_philo_thread(t_philosopher *philos, \
					t_program_data *pd, int id);

// Mutex inits
void			make_fork(t_program_data *pd, int id);

// Simulation goal checks
void			sim_death_checker(t_philosopher *philos);

#endif