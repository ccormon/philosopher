/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:13:14 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/15 17:44:27 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// faire des fonctions get_is_dead et set_is_dead
bool	philo_is_dead(t_philo *philo)
{
	static bool	is_dead = false;

	pthread_mutex_lock(&philo->args.mutex_is_dead);
	if (is_dead)
	{
		pthread_mutex_unlock(&philo->args.mutex_is_dead);
		return (true);
	}
	if (get_time() - philo->time_start_eating > philo->args.time_to_die)
	{
		printf("%s%ld %d died\n%s", RED, get_time() - philo->args.time_start,
			philo->philo_id, RESET_COLOR);
		is_dead = true;
		pthread_mutex_unlock(&philo->args.mutex_is_dead);
		return (true);
	}
	pthread_mutex_unlock(&philo->args.mutex_is_dead);
	return (false);
}

bool	ft_is_available(t_fork fork)
{
	bool	is_available;

	pthread_mutex_lock(&fork.mutex_is_available);
	is_available = fork.is_available;
	pthread_mutex_unlock(&fork.mutex_is_available);
	return (is_available);
}

bool	ft_eat_mutex_lock(t_philo *philo)
{
	while (!ft_is_available(philo->fork_left))
	{
		if (philo_is_dead(philo))
			return (false);
	}
	pthread_mutex_lock(&philo->fork_left.mutex_fork);
	philo->fork_left.is_available = false;
	printf("%s%ld %d has taken a fork\n%s", BLUE,
		get_time() - philo->args.time_start, philo->philo_id, RESET_COLOR);
	while (!ft_is_available(*philo->fork_right))
	{
		if (philo_is_dead(philo))
			return (false);
	}
	pthread_mutex_lock(&philo->fork_right->mutex_fork);
	philo->fork_right->is_available = false;
	printf("%s%ld %d has taken a fork\n%s", BLUE,
		get_time() - philo->args.time_start, philo->philo_id, RESET_COLOR);
	return (true);
}

void	ft_eat_mutex_unlock(t_philo *philo)
{
	philo->fork_left.is_available = true;
	pthread_mutex_unlock(&philo->fork_left.mutex_fork);
	philo->fork_right->is_available = true;
	pthread_mutex_unlock(&philo->fork_right->mutex_fork);
}
