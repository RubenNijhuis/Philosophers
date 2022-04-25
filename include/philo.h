/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:23:26 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/04/25 22:22:08 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> // pthread_mutex_t 
# include <stdbool.h> // true - false

// Enums
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
	bool			stop_sim;
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
	bool			stop_sim;
	int				amount_meals_eaten;
	pthread_mutex_t	amount_meals_lock;
	pthread_mutex_t	stop_sim_lock_local;
	t_program_data	*pd;
}	t_philosopher;

// Initialisation
bool	initiate_data(t_program_data *pd, char **argv);
bool	initiate_table(t_program_data *pd, t_philosopher *philos);

// General utilities
void	print_state(t_philosopher *philo, enum e_state state);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *src);
bool	validate_arguments(int argc, char **argv);
long	gettime(void);
void	*ft_bzero(void *ptr, size_t len);

// Philosopher actions
bool	action_eating(t_philosopher *philo);
bool	action_sleeping(t_philosopher *philo);
void	action_thinking(t_philosopher *philo);
void	*run_philosopher(void *philosopher);

// Thread utilities
void	close_threads(t_program_data *pd);
int		make_philo_thread(t_philosopher *philos, \
			t_program_data *pd, int id);
bool	stop_sim(t_philosopher *philo);
int		destroy_mutexes(t_philosopher *philos, \
			pthread_mutex_t stop_sim_lock, pthread_mutex_t print_lock);

// Death checker
void	*run_death_checker(void *philos_array);
int		create_sim_death_checker(t_philosopher *philos);

#endif
