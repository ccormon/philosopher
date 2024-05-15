/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:59:27 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/15 17:12:13 by ccormon          ###   ########.fr       */
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
	pthread_mutex_t	mutex_is_dead;
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
	t_args		args;
	pthread_t	thread_id;
	int			nb_meals;
	time_t		time_start_eating;
	t_fork		fork_left;
	t_fork		*fork_right;
}	t_philo;

/* ****************************** FONCTIONS ********************************* */

/* main.c */

/// @brief Create thread for each philosophers and start the simulation.
/// @param philo
void	start_simulation(t_philo *philo_tab, t_args args);

/* utils.c */

/// @brief It's like the libft's function ft_atoi but it can return only a
/// positive int and the string must be write in a restrictive format.
/// @param s
/// @return Return -1 if the string isn't OK or if the number isn't a positive
/// int. Return the number if everything is OK.
int		ft_atoi_mod(char *s);

/// @brief Give the time passed since 01/01/1970 midnight in milliseconds.
/// @return Return a time_t number.
time_t	get_time(void);

void	print_philo(t_philo *philo);

/* init.c */

/// @brief Initialize the structure args.
/// @param args
/// @param argv
/// @return Return false if one of the arguments isn't a number or if nb_philo
/// or nb_meals_max are equals to 0. Return true if everything is OK.
bool	init_args(t_args *args, char **argv);

/// @brief Initialize the structure philo for each philosophers and make a tab
/// with all of the structures. It needs to be free after using it.
/// @param args
/// @return  Return NULL if malloc fails. Return the tab philo_tab
/// initialized if everyting is OK.
t_philo	*init_philo_tab(t_args args);

/* routine.c */

void	ft_eat(t_philo *philo);

void	ft_sleep(t_philo *philo);

void	ft_think(t_philo *philo);

/// @brief Define the routine fowllowed by each philosophers.
/// @param arg
/// @return Always return NULL.
void	*start_routine(void *arg);

/* routine_utils.c */

/// @brief Determine if the philosopher is dead or not.
/// @param philo
/// @return Return true if the philosopher is dead and false if is not.
bool	philo_is_dead(t_philo *philo);

bool	ft_eat_mutex_lock(t_philo *philo);

void	ft_eat_mutex_unlock(t_philo *philo);

#endif
