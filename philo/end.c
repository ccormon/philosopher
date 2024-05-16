/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:12:47 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/16 17:13:58 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->mutex_is_dead);
	if (philo->args->is_dead)
	{
		pthread_mutex_unlock(&philo->args->mutex_is_dead);
		return (true);
	}
	if (get_time() - philo->time_start_eating > philo->args->time_to_die)
	{
		print_philo(philo, 0);
		philo->args->is_dead = true;
		pthread_mutex_unlock(&philo->args->mutex_is_dead);
		return (true);
	}
	pthread_mutex_unlock(&philo->args->mutex_is_dead);
	return (false);
}

bool	philo_can_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->mutex_end_simulation);
	if (philo->args->end_simulation)
	{
		pthread_mutex_unlock(&philo->args->mutex_end_simulation);
		return (false);
	}
	if (philo->nb_meals == philo->args->nb_meals_max)
	{
		philo->args->end_simulation = true;
		pthread_mutex_unlock(&philo->args->mutex_end_simulation);
		return (false);
	}
	pthread_mutex_unlock(&philo->args->mutex_end_simulation);
	return (true);
}
