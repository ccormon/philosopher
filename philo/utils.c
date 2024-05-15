/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:54:54 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/15 16:24:31 by ccormon          ###   ########.fr       */
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

// mutex sur printf pour eviter qu'ils s'ecrivent en meme temps
// void	print_philo(t_philo *philo)
// {

// }
