/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:13:14 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/16 17:14:00 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_is_available(t_fork fork)
{
	bool	is_available;

	pthread_mutex_lock(&fork.mutex_is_available);
	is_available = fork.is_available;
	pthread_mutex_unlock(&fork.mutex_is_available);
	return (is_available);
}

bool	ft_eat_mutex_lock_even(t_philo *philo)
{
	while (!ft_is_available(philo->fork_left))
	{
		if (philo_is_dead(philo) || !philo_can_eat(philo))
			return (false);
	}
	pthread_mutex_lock(&philo->fork_left.mutex_fork);
	philo->fork_left.is_available = false;
	print_philo(philo, 1);
	while (!philo->fork_right || !ft_is_available(*philo->fork_right))
	{
		if (philo_is_dead(philo) || !philo_can_eat(philo))
		{
			pthread_mutex_unlock(&philo->fork_left.mutex_fork);
			return (false);
		}
	}
	pthread_mutex_lock(&philo->fork_right->mutex_fork);
	philo->fork_right->is_available = false;
	print_philo(philo, 1);
	return (true);
}

bool	ft_eat_lock_mutex_odd(t_philo *philo)
{
	while (!philo->fork_right || !ft_is_available(*philo->fork_right))
	{
		if (philo_is_dead(philo) || !philo_can_eat(philo))
			return (false);
	}
	pthread_mutex_lock(&philo->fork_right->mutex_fork);
	philo->fork_right->is_available = false;
	print_philo(philo, 1);
	while (!ft_is_available(philo->fork_left))
	{
		if (philo_is_dead(philo) || !philo_can_eat(philo))
		{
			pthread_mutex_unlock(&philo->fork_right->mutex_fork);
			return (false);
		}
	}
	pthread_mutex_lock(&philo->fork_left.mutex_fork);
	philo->fork_left.is_available = false;
	print_philo(philo, 1);
	return (true);
}

bool	ft_eat_mutex_lock(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		return (ft_eat_mutex_lock_even(philo));
	else
		return (ft_eat_lock_mutex_odd(philo));
}

void	ft_eat_mutex_unlock(t_philo *philo)
{
	philo->fork_left.is_available = true;
	pthread_mutex_unlock(&philo->fork_left.mutex_fork);
	philo->fork_right->is_available = true;
	pthread_mutex_unlock(&philo->fork_right->mutex_fork);
}
