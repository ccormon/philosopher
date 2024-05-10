/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:59:27 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/10 16:40:20 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include "libft/libft.h"

# define NO_COLOR "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"

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
	t_fork		fork_left;
	t_fork		*fork_right;
}	t_philo

#endif
