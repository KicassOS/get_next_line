/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:56 by pszleper          #+#    #+#             */
/*   Updated: 2022/01/26 16:24:56 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
char	*get_next_line(int fd)
{
	char			*buffer;
	ssize_t			bytes_read;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	ft_clear_buffer(buffer);
	bytes_read = 1;
	while (bytes_read && ft_no_newline_found(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (ft_read_until_newline(buffer))
			return (buffer);
	}
	return (0);
}

char	*ft_read_until_newline(char *buffer)
{
	size_t	line_length;
	size_t	i;

	line_length = ft_line_length(buffer);
	while (i < line_length && buffer[i])
	{
		if (buffer[i++] == '\n')
		{
			if (buffer[i + 1])
			{
				buffer[i + 1] = '\0';
				return (buffer);
			}
		}
	}
	return (NULL);
}
