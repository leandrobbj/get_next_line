/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:07:55 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/14 18:36:38 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (*buffer)
		join_free_line(&line, buffer);
	if (!line)
		return (NULL);
	find_line(fd, &line, buffer);
	if (!line)
		return (NULL);
	clean_line(line, buffer);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("nls.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
