/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:03:35 by heljary           #+#    #+#             */
/*   Updated: 2024/11/28 10:44:31 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *rd_line(int fd, char *line)
{
    char *buffer;
    char *temp;
    int rd;

    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
    {
        return (NULL);
    }
    while(!ft_strchr(line,'\n') && (rd =read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[rd] = '\0';
        temp = line;
        line = ft_strjoin(line, buffer); 
        free(temp);
    }
    free(buffer);
    if (rd < 0)
        return (NULL);
    return (line);
}


char    *get_next_line(int fd)
{
    
}
