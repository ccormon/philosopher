/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:30:15 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/29 13:31:14 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	sublen;
	size_t	i;

	slen = ft_strlen(s);
	sublen = len;
	if (start >= slen)
	{
		start = slen;
		sublen = 0;
	}
	else if (len > slen - start)
		sublen = slen - start;
	sub = malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sublen && start + i < slen)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
