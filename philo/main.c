/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:58:32 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/11 17:31:24 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi_mod(char *s)
{
	unsigned long	n;
	int				i;

	if (!s || !(*s))
		return (-1);
	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		n = n * 10 + s[i++] - '0';
		if (n > INT_MAX)
			return (-1);
	}
	return (n);
}

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
		if (args->nb_meals_max <= 0)
			return (false);
	}
	else
		args->nb_meals_max = -1;
	return (true);
}

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
		philo[i].time_start_eating = 0;
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
	free(philo);
	return (EXIT_SUCCESS);
}
