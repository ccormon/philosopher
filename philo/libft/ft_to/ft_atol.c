/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:48:28 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/09 16:08:25 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atol(const char *s)
{
	unsigned long long	n;
	int					sign;
	size_t				i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	sign = 1;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
	{
		if (s[i++] == '-')
			sign = -1;
	}
	n = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		n = n * 10 + s[i++] - '0';
	return ((long)(sign * n));
}
