/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:57:30 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/16 17:22:13 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (!ft_eat_mutex_lock(philo))
		return ;
	print_philo(philo, 2);
	philo->nb_meals++;
	philo->time_start_eating = get_time();
	if (philo->time_start_eating + philo->args->time_to_die - get_time()
		>= philo->args->time_to_eat)
		usleep(philo->args->time_to_eat * 1000);
	else
		usleep((philo->time_start_eating + philo->args->time_to_die
				- get_time()) * 1000);
	ft_eat_mutex_unlock(philo);
}

void	ft_sleep(t_philo *philo)
{
	print_philo(philo, 3);
	if (philo->time_start_eating + philo->args->time_to_die - get_time()
		>= philo->args->time_to_sleep)
		usleep(philo->args->time_to_eat * 1000);
	else
		usleep((philo->time_start_eating + philo->args->time_to_die
				- get_time()) * 1000);
}

void	ft_think(t_philo *philo)
{
	print_philo(philo, 4);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->time_start_eating = get_time();
	if (!philo_is_dead(philo) && philo_can_eat(philo))
		ft_think(philo);
	if ((!philo_is_dead(philo) && philo_can_eat(philo))
		&& philo->philo_id % 2 != 0)
		usleep(philo->args->time_to_eat * 1000);
	while (!philo_is_dead(philo) && philo_can_eat(philo))
	{
		if (!philo_is_dead(philo) && philo_can_eat(philo))
			ft_eat(philo);
		if (!philo_is_dead(philo) && philo_can_eat(philo))
			ft_sleep(philo);
		if (!philo_is_dead(philo) && philo_can_eat(philo))
			ft_think(philo);
	}
	return (NULL);
}
