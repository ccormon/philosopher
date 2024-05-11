/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:59:27 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/11 17:36:42 by ccormon          ###   ########.fr       */
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
# include "libft/libft.h"

/* ******************************* DEFINES ********************************** */

# define NO_COLOR "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"

/* ****************************** STRUCTURES ******************************** */

typedef struct s_args
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_meals_max;
}	t_args;

typedef struct s_fork
{
	bool			is_available;
	pthread_mutex_t	*mutex;
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread_id;
	int			nb_meals;
	bool		is_eating;
	bool		is_sleeping;
	bool		is_thinking;
	int			time_start_eating;
	t_fork		fork_left;
	t_fork		*fork_right;
}	t_philo;

/* ****************************** FONCTIONS ********************************* */

/// @brief It's like the libft's function ft_atoi but it can return only a
/// positive int and the string must be write in a restrictive format.
/// @param s
/// @return Return -1 if the string isn't OK or if the number isn't a positive
/// int. Return the number if everything is OK.
int		ft_atoi_mod(char *s);

/// @brief Initialize the structure args.
/// @param args
/// @param argv
/// @return Return false if one of the arguments isn't a number or if nb_philo
/// or nb_meals_max are equals to 0. Return true if everything is OK.
bool	init_args(t_args *args, char **argv);

/// @brief Initialize the structure philo. It needs to be free after using it.
/// @param args
/// @return  Return NULL if malloc fails. Return the structure philo
/// initialized if everyting is OK.
t_philo	*init_philo(t_args args);

#endif
