/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:59:55 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/29 13:31:14 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	int		i;

	if (!((char *)dest) && !((char *)src))
		return (NULL);
	temp = (char *)src;
	if ((char *)dest < (char *)src)
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(temp + i);
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(temp + i);
			i--;
		}
	}
	return (dest);
}
