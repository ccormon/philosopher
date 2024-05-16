/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:59:27 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/16 17:48:45 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ******************************* INCLUDES ********************************* */

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

/* ******************************* DEFINES ********************************** */

# define RESET_COLOR "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"

/* ****************************** STRUCTURES ******************************** */

typedef struct s_args
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals_max;
	time_t			time_start;
	bool			is_dead;
	pthread_mutex_t	mutex_is_dead;
	bool			end_simulation;
	pthread_mutex_t	mutex_end_simulation;
	pthread_mutex_t	mutex_print_philo;
}	t_args;

typedef struct s_fork
{
	bool			is_available;
	pthread_mutex_t	mutex_is_available;
	pthread_mutex_t	mutex_fork;
}	t_fork;

typedef struct s_philo
{
	int			philo_id;
	t_args		*args;
	pthread_t	thread_id;
	int			nb_meals;
	time_t		time_start_eating;
	t_fork		fork_left;
	t_fork		*fork_right;
}	t_philo;

/* ****************************** FONCTIONS ********************************* */

/* main.c */

/// @brief Creates thread for each philosophers, start the simulation, then
/// destroy all the mutex at the end.
/// @param philo_tab
/// @param args
void	start_simulation(t_philo *philo_tab, t_args args);

/* utils.c */

/// @brief It's like the libft's function ft_atoi but it can return only a
/// positive int and the string must be write in a restrictive format.
/// @param s
/// @return Returns -1 if the string isn't OK or if the number isn't a positive
/// int. Returns the number if everything is OK.
int		ft_atoi_mod(char *s);

/// @brief Gives the time passed since 01/01/1970 midnight in milliseconds.
/// @return Returns a time_t number.
time_t	get_time(void);

/// @brief Displays all the change of state of the philosophers according to
/// code.
/// @param philo
/// @param code
void	print_philo(t_philo *philo, int code);

/* init.c */

/// @brief Initializes the structure args.
/// @param args
/// @param argv
/// @return Returns false if one of the arguments isn't a number or if nb_philo
/// or nb_meals_max are equals to 0. Returns true if everything is OK.
bool	init_args(t_args *args, char **argv);

/// @brief Initializes the structure philo for each philosophers and make a tab
/// with all of the structures. It needs to be free after using it.
/// @param args
/// @return  Returns NULL if malloc fails. Returns the tab philo_tab
/// initialized if everyting is OK.
t_philo	*init_philo_tab(t_args args);

/* routine.c */

/// @brief Simulates the eating of the philosopher. He must eat time_to_eat
/// milliseconds unless he dies before.
/// @param philo
void	ft_eat(t_philo *philo);

/// @brief Simulates the sleeping of the philosopher. He must sleep
/// time_to_sleep milliseconds unless he dies before.
/// @param philo
void	ft_sleep(t_philo *philo);

/// @brief Simulates the thinking of the philosopher. He must think until he can
/// eat unless he dies before.
/// @param philo
void	ft_think(t_philo *philo);

/// @brief Defines the routine fowllowed by each philosophers.
/// @param arg
/// @return Always returns NULL.
void	*start_routine(void *arg);

/* routine_utils.c */

/// @brief Checks if the fork is available or not.
/// @param fork
/// @return Returns true if the fork is available and false otherwise.
bool	ft_is_available(t_fork fork);

/// @brief Locks the mutexes of the two forks required by the philosopher so he
/// can eat but only for the philosophers with an even ID.
/// @param philo
/// @return Returns false if the simulation ends before the philosopher can take
/// the two forks and true otherwise.
bool	ft_eat_mutex_lock_even(t_philo *philo);

/// @brief Locks the mutexes of the two forks required by the philosopher so he
/// can eat but only for the philosophers with an odd ID.
/// @param philo
/// @return Returns false if the simulation ends before the philosopher can take
/// the two forks and true otherwise.
bool	ft_eat_lock_mutex_odd(t_philo *philo);

/// @brief Manages the lock of the mutexes of the two forks required by the
/// philosopher so he can eat.
/// @param philo
/// @return Returns false if the simulation ends before the philosopher can take
/// the two forks and true otherwise.
bool	ft_eat_mutex_lock(t_philo *philo);

/// @brief Unlocks locked mutexes so the philosopher can eat.
/// @param philo
void	ft_eat_mutex_unlock(t_philo *philo);

/* end.c */

/// @brief Determines one of the philosophers is dead or not.
/// @param philo
/// @return Return true if the philosopher is dead and false otherwise.
bool	philo_is_dead(t_philo *philo);

/// @brief Determines if the philosopher can eat or not depending of
/// nb_meals_max.
/// @param philo
/// @return Returns true if the philosopher can eat and false otherwise.
bool	philo_can_eat(t_philo *philo);

#endif
