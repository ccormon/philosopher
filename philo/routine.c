/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:57:30 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/15 16:19:23 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (philo->args.nb_meals_max != -1
		&& philo->nb_meals >= philo->args.nb_meals_max)
		return ;
	if (!ft_eat_mutex_lock(philo))
		return ;
	printf("%s%ld %d is eating\n%s", YELLOW,
		get_time() - philo->args.time_start, philo->philo_id, RESET_COLOR);
	philo->nb_meals++;
	philo->time_start_eating = get_time();
	if (philo->time_start_eating + philo->args.time_to_die - get_time()
		>= philo->args.time_to_eat)
		usleep(philo->args.time_to_eat * 1000);
	else
		usleep((philo->time_start_eating + philo->args.time_to_die
				- get_time()) * 1000);
	ft_eat_mutex_unlock(philo);
}

void	ft_sleep(t_philo *philo)
{
	printf("%s%ld %d is sleeping\n%s", GREEN,
		get_time() - philo->args.time_start, philo->philo_id, RESET_COLOR);
	if (philo->time_start_eating + philo->args.time_to_die - get_time()
		>= philo->args.time_to_sleep)
		usleep(philo->args.time_to_eat * 1000);
	else
		usleep((philo->time_start_eating + philo->args.time_to_die
				- get_time()) * 1000);
}

void	ft_think(t_philo *philo)
{
	printf("%s%ld %d is thinking\n%s", MAGENTA,
		get_time() - philo->args.time_start, philo->philo_id, RESET_COLOR);
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
