/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:03:35 by heljary           #+#    #+#             */
/*   Updated: 2024/12/04 22:32:28 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*rd_line(int fd, char *str, char *buffer)
{
	ssize_t	b_read;
	char	*temp;

	b_read = read(fd, buffer, BUFFER_SIZE);
	while (b_read > 0)
	{
		buffer[b_read] = '\0';
		if (!str)
			str = ft_strdup("");
		temp = ft_strjoin(str, buffer);
		free(str);
		if (!temp)
			return (NULL);
		str = temp;
		if (ft_strchr(str, '\n'))
			break ;
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (b_read < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (str);
}

static char	*rm_line(char *line)
{
	int		i;
	char	*remainder;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	remainder = ft_strdup(line + i + 1);
	if (!remainder || *remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[i + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char		*str[1024];
	char			*buffer;
	char			*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = rd_line(fd, str[fd], buffer);
	free(buffer);
	if (!line)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = rm_line(line);
	return (line);
}
