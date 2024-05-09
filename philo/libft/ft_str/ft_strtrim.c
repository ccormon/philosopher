/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:20:41 by marvin            #+#    #+#             */
/*   Updated: 2024/02/29 13:31:14 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
//#include <stdio.h>

int	ft_trimstart(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

int	ft_trimend(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1);
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*news1;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_trimstart(s1, set);
	end = ft_trimend(s1, set);
	if (start > end)
		return (ft_strdup(""));
	news1 = malloc((end - start + 2) * sizeof(char));
	if (!news1)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		news1[i] = s1[start];
		start++;
		i++;
	}
	news1[i] = '\0';
	return (news1);
}
