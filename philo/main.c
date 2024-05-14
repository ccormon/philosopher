/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:58:32 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/14 16:44:34 by ccormon          ###   ########.fr       */
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

time_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
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
	args->time_start_simulation = get_time();
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
		philo_tab[i].args = args;
		philo_tab[i].nb_meals = 0;
		philo_tab[i].fork_left.is_available = true;
		pthread_mutex_init(&philo_tab[i++].fork_left.mutex, NULL);
	}
	philo_tab[0].fork_right = &philo_tab[args.nb_philo - 1].fork_left;
	i = 1;
	while (i < args.nb_philo)
	{
		philo_tab[i].fork_right = &philo_tab[i - 1].fork_left;
		i++;
	}
	return (philo_tab);
}

bool	philo_is_dead(t_philo *philo)
{
	static bool	is_dead = false;

	if (is_dead)
		return (true);
	if (get_time() - philo->time_start_eating > philo->args.time_to_die)
	{
		printf("%s%ld %d died\n%s", RED, get_time() -
			philo->args.time_start_simulation, philo->philo_id, RESET_COLOR);
		is_dead = true;
		return (true);
	}
	return (false);
}

void	*start_routine_one_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo_is_dead(philo));
	return (NULL);
}

bool	ft_mutex_lock(t_philo *philo)
{
	while (!philo->fork_left.is_available)
	{
		if (philo_is_dead(philo))
			return (false);
	}
	pthread_mutex_lock(&philo->fork_left.mutex);
	philo->fork_left.is_available = false;
	printf("%s%ld %d has taken a fork\n%s", BLUE, get_time() -
			philo->args.time_start_simulation, philo->philo_id, RESET_COLOR);
	while (!philo->fork_right->is_available)
	{
		if (philo_is_dead(philo))
			return (false);
	}
	pthread_mutex_lock(&philo->fork_right->mutex);
	philo->fork_right->is_available = false;
	printf("%s%ld %d has taken a fork\n%s", BLUE, get_time() -
			philo->args.time_start_simulation, philo->philo_id, RESET_COLOR);
	return (true);
}

void	ft_mutex_unlock(t_philo *philo)
{
	philo->fork_left.is_available = true;
	pthread_mutex_unlock(&philo->fork_left.mutex);
	philo->fork_right->is_available = true;
	pthread_mutex_unlock(&philo->fork_right->mutex);
}

void	ft_eat(t_philo *philo)
{
	if (philo->args.nb_meals_max != -1
		&& philo->nb_meals >= philo->args.nb_meals_max)
		return ;
	if (!ft_mutex_lock(philo))
		return ;
	printf("%s%ld %d is eating\n%s", YELLOW, get_time() -
			philo->args.time_start_simulation, philo->philo_id, RESET_COLOR);
	philo->nb_meals++;
	philo->time_start_eating = get_time();
	if (get_time() - philo->time_start_eating + philo->args.time_to_eat
		< philo->args.time_to_die)
		usleep(philo->args.time_to_eat * 1000);
	else
		usleep((get_time() - philo->time_start_eating
			+ philo->args.time_to_die) * 1000);
	ft_mutex_unlock(philo);
}

void	ft_sleep(t_philo *philo)
{
	printf("%s%ld %d is sleeping\n%s", GREEN, get_time() -
			philo->args.time_start_simulation, philo->philo_id, RESET_COLOR);
	if (get_time() - philo->time_start_eating + philo->args.time_to_sleep
		< philo->args.time_to_die)
		usleep(philo->args.time_to_sleep * 1000);
	else
		usleep((get_time() - philo->time_start_eating
			+ philo->args.time_to_die) * 1000);
}

void	ft_think(t_philo *philo)
{
	printf("%s%ld %d is thinking\n%s", MAGENTA, get_time() -
			philo->args.time_start_simulation, philo->philo_id, RESET_COLOR);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->time_start_eating = get_time();
	while (!philo_is_dead(philo))
	{
		if (!philo_is_dead(philo))
			ft_think(philo);
		if (!philo_is_dead(philo))
			ft_eat(philo);
		if (!philo_is_dead(philo))
			ft_sleep(philo);
	}
	return (NULL);
}

void	start_simulation(t_philo **philo_tab)
{
	int	i;

	if (philo_tab[0]->args.nb_philo == 1)
	{
		pthread_create(&philo_tab[0]->thread_id, NULL, start_routine_one_philo,
			philo_tab[0]);
		pthread_join(philo_tab[0]->thread_id, NULL);
		return ;
	}
	i = 0;
	while (i < philo_tab[i]->args.nb_philo)
	{
		pthread_create(&philo_tab[i]->thread_id, NULL, start_routine,
			philo_tab[i]);
		i++;
	}
	i = 0;
	while (i < philo_tab[i]->args.nb_philo)
		pthread_join(philo_tab[i++]->thread_id, NULL);
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
	philo_tab = init_philo_tab(args);
	if (!philo_tab)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	start_simulation(&philo_tab);
	free(philo_tab);
	return (EXIT_SUCCESS);
}
