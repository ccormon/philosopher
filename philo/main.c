/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:58:32 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/10 16:35:11 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Initialize the struct args.
Return false if one of the arguments isn't a number or if nb_philo or
 nb_meals_max are equals to 0.*/
bool	init_args(t_args *args, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		if (!ft_isnumber(argv[i++]))
			return (false);
	args->nb_philo = ft_atoi(argv[0]);
	args->time_to_die = ft_atoi(argv[1]);
	args->time_to_eat = ft_atoi(argv[2]);
	args->time_to_sleep = ft_atoi(argv[3]);
	if (argv[4])
		args->nb_meals_max = ft_atoi(argv[4]);
	else
		args->nb_meals_max = -1;
	if (args->nb_philo == 0 || args->nb_meals_max == 0)
		return (false);
	return (true);
}

/*
Initialize the struct philo. It needs to be free after.
Return NULL if malloc fails and the struct philo initialized if everyting is
 OK.*/
t_philo	*init_philo(t_args args)
{
	t_philo	*philo;
	int		i;

	philo = malloc(args.nb_philo * sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < args.nb_philo)
	{
		philo[i].nb_meals = 0;
		philo[i].is_eating = false;
		philo[i].is_sleeping = false;
		philo[i].is_thinking = true;
		philo[i].fork_left.is_available = true;
		pthread_mutex_init(philo[i++].fork_left.mutex, NULL);
	}
	philo[0].fork_right = &philo[args.nb_philo - 1].fork_left;
	i = 1;
	while (i < args.nb_philo)
	{
		philo[i].fork_right = &philo[i - 1].fork_left;
		i++;
	}
	return (philo);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!init_args(&args, argv + 1))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	philo = init_philo(args);
	if (!philo)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
