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
	static ssize_t	position;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	ft_clear_buffer(buffer);
	bytes_read = 1;
	position = 0;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		position += ft_read__until_newline(buffer);
	}
	return (buffer);
}

ssize_t	ft_read_until_newline(char *buffer)
{
	size_t	line_length;

	line_length = ft_line_length(buffer);
	printf("%lu\n", line_length);
	return (line_length);
}
