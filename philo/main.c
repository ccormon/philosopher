/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:58:32 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/15 17:21:05 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_philo *philo_tab, t_args args)
{
	int	i;

	i = 0;
	while (i < args.nb_philo)
	{
		pthread_create(&philo_tab[i].thread_id, NULL, &start_routine,
			&philo_tab[i]);
		i++;
	}
	i = 0;
	while (i < args.nb_philo)
		pthread_join(philo_tab[i++].thread_id, NULL);
	pthread_mutex_destroy(&args.mutex_is_dead);
	i = 0;
	while (i < args.nb_philo)
	{
		pthread_mutex_destroy(&philo_tab[i].fork_left.mutex_is_available);
		pthread_mutex_destroy(&philo_tab[i++].fork_left.mutex_fork);
	}
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philo_tab;

	if (argc != 5 && argc != 6)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	if (!init_args(&args, argv + 1))
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	if (args.nb_meals_max == 0)
		return (EXIT_SUCCESS);
	philo_tab = init_philo_tab(args);
	if (!philo_tab)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	start_simulation(philo_tab, args);
	free(philo_tab);
	return (EXIT_SUCCESS);
}
