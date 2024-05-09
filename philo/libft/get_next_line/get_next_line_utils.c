/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:04:17 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/29 13:28:50 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_isinstr(char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	if (str[i] == c)
		return (true);
	return (false);
}

void	addtoreaded(char **readed, char *buffer)
{
	char	*temp;
	size_t	i;
	size_t	j;

	temp = malloc((ft_strlen(*readed) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!temp)
		return ;
	i = 0;
	if (*readed)
	{
		while ((*readed)[i])
		{
			temp[i] = (*readed)[i];
			i++;
		}
	}
	j = 0;
	while (buffer[j])
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	free(*readed);
	*readed = temp;
}

char	*addtoline(char *readed)
{
	char	*line;
	size_t	i;

	i = 0;
	while (readed[i] && readed[i] != '\n')
		i++;
	if (i == 0 && readed[i] != '\n')
		return (NULL);
	if (readed[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (readed[i] && readed[i] != '\n')
	{
		line[i] = readed[i];
		i++;
	}
	if (readed[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

void	cleanreaded(char **readed)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while ((*readed)[i] && (*readed)[i] != '\n')
		i++;
	if (!((*readed)[i]))
	{
		free(*readed);
		*readed = NULL;
		return ;
	}
	temp = malloc((ft_strlen(*readed) - i + 1) * sizeof(char));
	if (!temp)
		return ;
	i++;
	j = 0;
	while ((*readed)[i])
		temp[j++] = (*readed)[i++];
	temp[j] = '\0';
	free(*readed);
	*readed = temp;
}
