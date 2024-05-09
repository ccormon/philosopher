/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:04:21 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/29 13:28:45 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

ssize_t	readline(ssize_t byte_read, char *buffer, char **readed, int fd)
{
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read <= 0)
		return (byte_read);
	buffer[byte_read] = '\0';
	addtoreaded(readed, buffer);
	return (byte_read);
}

char	*get_next_line(int fd)
{
	static char	*readed = NULL;
	char		*buffer;
	char		*line;
	ssize_t		byte_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = BUFFER_SIZE;
	while (byte_read == BUFFER_SIZE && !ft_strchr(readed, '\n'))
		byte_read = readline(byte_read, buffer, &readed, fd);
	free(buffer);
	if (byte_read == -1)
	{
		free(readed);
		readed = NULL;
		return (NULL);
	}
	if (!readed)
		return (NULL);
	line = addtoline(readed);
	cleanreaded(&readed);
	return (line);
}

/* int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			printf("%s", line);
		}
		close(fd);
	}
	return (0);
}
 */
