/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:06:24 by marvin            #+#    #+#             */
/*   Updated: 2024/02/29 13:31:14 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_number_len(long long int n)
{
	int	nbrlen;

	nbrlen = 1;
	if (n >= 0 && n <= 9)
		return (nbrlen);
	if (n < 0)
	{
		n *= -1;
		nbrlen++;
	}
	while (n >= 10)
	{
		n /= 10;
		nbrlen++;
	}
	return (nbrlen);
}

int	ft_power(int n, int power)
{
	int	nbr;
	int	i;

	if (power == 0)
		return (1);
	nbr = n;
	i = 1;
	while (i < power)
	{
		nbr *= n;
		i++;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			nbrlen;
	int			i;
	long long	number;

	number = n;
	nbrlen = ft_number_len(number);
	nbr = malloc((nbrlen + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	i = 0;
	if (number < 0)
	{
		nbr[i++] = '-';
		number *= -1;
	}
	while (i < nbrlen)
	{
		nbr[i] = '0' + number / ft_power(10, nbrlen - i - 1);
		number %= ft_power(10, nbrlen - i++ - 1);
	}
	nbr[i] = '\0';
	return (nbr);
}
