/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:55:51 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/16 17:11:46 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_args(t_args *args, char **argv)
{
	args->nb_philo = ft_atoi_mod(argv[0]);
	if (args->nb_philo <= 0)
		return (false);
	args->time_to_die = ft_atoi_mod(argv[1]);
	if (args->time_to_die < 0)
		return (false);
	args->time_to_eat = ft_atoi_mod(argv[2]);
	if (args->time_to_eat < 0)
		return (false);
	args->time_to_sleep = ft_atoi_mod(argv[3]);
	if (argv[4])
	{
		args->nb_meals_max = ft_atoi_mod(argv[4]);
		if (args->nb_meals_max < 0)
			return (false);
	}
	else
		args->nb_meals_max = -1;
	args->time_start = get_time();
	args->is_dead = false;
	pthread_mutex_init(&args->mutex_is_dead, NULL);
	args->end_simulation = false;
	pthread_mutex_init(&args->mutex_end_simulation, NULL);
	pthread_mutex_init(&args->mutex_print_philo, NULL);
	return (true);
}

t_philo	*init_philo_tab(t_args args)
{
	t_philo	*philo_tab;
	int		i;

	philo_tab = malloc(args.nb_philo * sizeof(t_philo));
	if (!philo_tab)
		return (NULL);
	i = 0;
	while (i < args.nb_philo)
	{
		philo_tab[i].philo_id = i;
		philo_tab[i].args = &args;
		philo_tab[i].nb_meals = 0;
		philo_tab[i].fork_left.is_available = true;
		pthread_mutex_init(&philo_tab[i].fork_left.mutex_is_available, NULL);
		pthread_mutex_init(&philo_tab[i++].fork_left.mutex_fork, NULL);
	}
	if (args.nb_philo > 1)
		philo_tab[0].fork_right = &philo_tab[args.nb_philo - 1].fork_left;
	else
		philo_tab[0].fork_right = NULL;
	i = 0;
	while (++i < args.nb_philo)
		philo_tab[i].fork_right = &philo_tab[i - 1].fork_left;
	return (philo_tab);
}
