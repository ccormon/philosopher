/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:58:32 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/09 16:32:08 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_args(t_args *args, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		if (!ft_isnumber(argv[i++]))
			return (false);
	args->nb_philo = ft_atoi(argv[0]);
	args->time_to_die = ft_atol(argv[1]);
	args->time_to_eat = ft_atol(argv[2]);
	args->time_to_sleep = ft_atol(argv[3]);
	if (argv[4])
		args->nb_meals_max = ft_atol(argv[4]);
	else
		args->nb_meals_max = -1;
	return (true);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
	{
		printf("%sError\n%sWRONG NUMBER OF ARGUMENTS\nYou must write something\
 like :\n\t%snumber_of_philosophers %stime_to_die %stime_to_eat %stime_to_slee\
p %s[number_of_times_each_philosopher_must_eat]\n", RED, NO_COLOR, RED, GREEN,
 			YELLOW, BLUE, NO_COLOR);
		return (EXIT_FAILURE);
	}
	if (!init_args(&args, argv + 1))
	{
		printf("%sError\n%sWRONG FORMAT\nYou must give only numbers\n", RED,
			NO_COLOR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
