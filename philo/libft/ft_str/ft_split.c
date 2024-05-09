/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:07:45 by marvin            #+#    #+#             */
/*   Updated: 2024/02/29 13:31:14 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_countword(char const *s, char c)
{
	int	nbword;
	int	i;

	if (s[0] == '\0')
		return (0);
	nbword = 0;
	i = 0;
	if (s[i] != c)
	{
		nbword++;
		i++;
	}
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			nbword++;
		i++;
	}
	return (nbword);
}

char	*ft_allocword(char const *s, char c, int const i)
{
	char	*word;
	int		j;

	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
		j++;
	word = malloc((j + 1) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (s[i + j] && s[i + j] != c)
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbword;
	int		word;
	int		i;

	if (!s || !(*s))
		return (NULL);
	nbword = ft_countword(s, c);
	tab = (char **)malloc((nbword + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i] && word < nbword)
	{
		if ((i > 0 && s[i - 1] == c && s[i] != c) || (i == 0 && s[i] != c))
			tab[word++] = ft_allocword(s, c, i);
		i++;
	}
	tab[word] = NULL;
	return (tab);
}
