/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:48:07 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/06 17:40:45 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	join_free_line(char **line, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = ft_strlen(*line);
	j = ft_strlen(buffer);
	str = malloc((i + j + 1) * sizeof(char));
	if (!str)
		return ;
	str[i + j] = '\0';
	while (j--)
		str[i + j] = buffer[j];
	while (i--)
		str[i] = (*line)[i];
	free(*line);
	*line = str;
}

void	find_line(int fd, char **line, char *buffer)
{
	ssize_t		bytes;

	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(*line);
			*line = NULL;
			buffer[0] = '\0';
			return ;
		}
		buffer[bytes] = '\0';
		join_free_line(line, buffer);
	}
}

void	clean_line(char *line, char *buffer)
{
	size_t	i;
	char	*needle;

	i = 0;
	needle = ft_strchr(line, '\n');
	if (needle)
		needle[1] = '\0';
	needle = ft_strchr(buffer, '\n');
	if (!needle)
		buffer[0] = '\0';
	else
	{
		needle++;
		while (needle[i])
		{
			buffer[i] = needle[i];
			i++;
		}
		buffer[i] = '\0';
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
