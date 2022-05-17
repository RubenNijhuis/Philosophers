/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 10:23:26 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/17 22:06:09 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>	// pthread_mutex_t
# include <stdbool.h>	// bool
# include <stdint.h>	// uint32_t

// Current philo state for print_state
typedef enum e_state
{
	sleeping,
	eating,
	pick_up_fork,
	died,
	thinking
}	t_state;

# define ACTION_INTERVAL 250
# define CHECKER_INTERVAL 250

// Program data struct
typedef struct s_program_data
{
	uint32_t		amount_philos;

	uint32_t		time_to_die;
	uint32_t		time_to_eat;
	uint32_t		time_to_sleep;
	uint32_t		amount_meals;

	uint32_t		start_time;

	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_sim_lock;
	bool			stop_sim;

	pthread_mutex_t	*forks;
	pthread_t		*philo_threads;
}	t_program_data;

// Philosopher struct
typedef struct s_philosopher
{
	uint32_t		id;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	uint32_t		last_time_eaten;
	uint32_t		amount_meals_eaten;
	pthread_mutex_t	amount_meals_lock;

	t_program_data	*pd;
}	t_philosopher;

// Initialize
bool		initiate_data(t_program_data *pd, char **argv);
bool		initiate_table(t_program_data *pd, t_philosopher *philos);

// Utils
void		print_state(t_philosopher *philo, t_state state);
void		*ft_calloc(size_t count, size_t size);
int32_t		ft_atoi(const char *src);
bool		validate_arguments(uint32_t argc, char **argv);
uint32_t	gettime(void);
void		*ft_bzero(void *ptr, size_t len);

// Philosopher
bool		action_eating(t_philosopher *philo);
bool		action_sleeping(t_philosopher *philo);
bool		action_thinking(t_philosopher *philo);
void		increment_amount_times_eaten(t_philosopher *philo);
void		*run_philosopher(void *philosopher);

// Thread utils
void		join_threads(uint32_t amount_philos, pthread_t *philo_threads);
bool		make_philo_thread(t_philosopher *philos, \
				t_program_data *pd, uint32_t id);
bool		stop_sim(t_philosopher *philo);
int32_t		destroy_mutexes(t_philosopher *philos, \
				pthread_mutex_t stop_sim_lock, pthread_mutex_t print_lock);

// Simulation goal checks
void		*run_death_checker(void *philos_array);
bool		create_sim_death_checker(t_philosopher *philos);

#endif
