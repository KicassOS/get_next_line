/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:56 by pszleper          #+#    #+#             */
/*   Updated: 2022/02/12 04:50:33 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	ssize_t		bytes_read;
	ssize_t		nl_index;

	if (fd < 0)
		return (NULL);
	line = ft_calloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	bytes_read = 1;
	while (bytes_read && ft_no_newline_found(line))
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		nl_index = ft_read_until_newline(line);
		if (nl_index > 0)
		{
			if (ft_stash_remainder(&stash, line, bytes_read - nl_index))
				return (NULL);
			return (line);
		}
	}
	return (0);
}

char	ft_stash_remainder(char *stash, char *line, ssize_t stash_size)
{
	if (!stash)
	{
		stash = ft_calloc(stash_size);
		if (!stash)
			return (NULL);
	}
	
}
