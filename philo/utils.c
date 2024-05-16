/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:54:54 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/16 17:10:24 by ccormon          ###   ########.fr       */
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

void	print_philo(t_philo *philo, int code)
{
	pthread_mutex_lock(&philo->args->mutex_print_philo);
	if (code == 0)
		printf("%s%ld %d died\n%s", RED, get_time() - philo->args->time_start,
			philo->philo_id, RESET_COLOR);
	else if (code == 1)
		printf("%s%ld %d has taken a fork\n%s", BLUE,
			get_time() - philo->args->time_start, philo->philo_id,
			RESET_COLOR);
	else if (code == 2)
		printf("%s%ld %d is eating\n%s", YELLOW,
			get_time() - philo->args->time_start, philo->philo_id,
			RESET_COLOR);
	else if (code == 3)
		printf("%s%ld %d is sleeping\n%s", GREEN,
			get_time() - philo->args->time_start, philo->philo_id,
			RESET_COLOR);
	else if (code == 4)
		printf("%s%ld %d is thinking\n%s", MAGENTA,
			get_time() - philo->args->time_start, philo->philo_id,
			RESET_COLOR);
	pthread_mutex_unlock(&philo->args->mutex_print_philo);
}
