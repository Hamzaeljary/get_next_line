/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:03:35 by heljary           #+#    #+#             */
/*   Updated: 2024/12/02 18:08:55 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rd_line(int fd, char *line)
{
	char	*buffer;
	int		rd;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	while (!(ft_strchr(line, '\n')))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buffer[rd] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	if (rd < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ext_line(char **rem, char *line)
{
	char	*temp;

	if (ft_strchr(line, '\n'))
	{
		*rem = ft_strdup(ft_strchr(line, '\n') + 1);
		temp = line;
		line = ft_substr(line, 0, ft_strchr(line, '\n') - line + 1);
		free(temp);
		if (!line)
			return (NULL);
	}
	else
	{
		if (*rem)
			free(*rem);
		*rem = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	if (rem)
	{
		line = ft_strdup(rem);
		free(rem);
		rem = NULL;
	}
	else
	{
		line = ft_strdup("");
	}
	if (!line)
		return (NULL);
	line = rd_line(fd, line);
	if (!line || !line[0])
		free(line);
	return (NULL);
	return (ext_line(&rem, line));
}
