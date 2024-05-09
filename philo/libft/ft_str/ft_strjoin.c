/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:36:26 by marvin            #+#    #+#             */
/*   Updated: 2024/02/29 13:31:14 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s0;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s0 = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s0[i] = s1[i];
		i++;
	}
	while (s2[i - s1_len])
	{
		s0[i] = s2[i - s1_len];
		i++;
	}
	s0[i] = '\0';
	return (s0);
}
