/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:27:43 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/29 13:31:14 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printfunbr(unsigned int n)
{
	int	nlen;

	ft_putnbr(n);
	nlen = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		nlen++;
	}
	return (nlen);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned long long n, char *basehex)
{
	if (n < 16)
	{
		if (n % 16 < 10)
			ft_putchar('0' + n % 16);
		else
			ft_putchar(basehex[10] + n % 16 - 10);
		return ;
	}
	ft_puthex(n / 16, basehex);
	if (n % 16 < 10)
		ft_putchar('0' + n % 16);
	else
		ft_putchar(basehex[10] + n % 16 - 10);
}

void	ft_putnbr(unsigned int n)
{
	if (n < 10)
	{
		ft_putchar('0' + n);
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
