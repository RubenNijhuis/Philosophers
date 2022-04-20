/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:23:26 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/20 14:04:02 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

// Enums
enum e_bool { false, true };
enum e_state { sleeping, eating, pick_up_fork, died, thinking };

// Program data struct
typedef struct s_program_data
{
	int				amount_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				amount_meals;
	long			start_time;
	enum e_bool		stop_sim;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_sim_lock;
	pthread_mutex_t	forks[200];
	pthread_t		philo_threads[200];
}	t_program_data;

// Philosopher struct
typedef struct s_philosopher
{
	int				id;
	long			last_time_eaten;
	int				left_fork;
	int				right_fork;
	enum e_bool		stop_sim;
	int				amount_meals_eaten;
	pthread_mutex_t	amount_meals_lock;
	pthread_mutex_t	stop_sim_lock_local;
	t_program_data	*pd;
}	t_philosopher;

// Initialize
void			initiate_data(t_program_data *pd, char **argv);
void			initiate_table(t_program_data *pd);

// Utils
void			print_state(t_philosopher *philo, enum e_state state);
enum e_bool		is_only_number(char *str);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *src);
enum e_bool		validate_arguments(int argc, char **argv);
long int		gettime(void);

// Philo
enum e_bool		action_eating(t_philosopher *philo);
enum e_bool		action_sleeping(t_philosopher *philo);
void			action_thinking(t_philosopher *philo);
void			*run_philosopher(void *philosopher);

// Thread utils
void			close_threads(t_program_data *pd);
void			make_philo_thread(t_philosopher *philos, \
					t_program_data *pd, int id);
enum e_bool		stop_sim(t_philosopher *philo);
void			destroy_mutexes(t_philosopher *philos);
void			make_fork(t_program_data *pd, int id);

// Simulation goal checks
void			*run_death_checker(void *philos_array);
void			create_sim_death_checker(t_philosopher *philos);

#endif
