/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:56 by pszleper          #+#    #+#             */
/*   Updated: 2022/03/08 00:01:11 by pszleper         ###   ########.fr       */
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	bytes_read = 1;
	while (bytes_read && ft_no_newline_found(line))
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
			return (NULL);
		nl_index = ft_nl_index(line);
		if (nl_index >= 0)
		{
			if (!ft_stash(stash, line, bytes_read - nl_index, nl_index))
				return (NULL);
			return (line);
		}
	}
	return (0);
}

char	ft_stash(char *stash, char *line, ssize_t stash_size, ssize_t nl_index)
{
	size_t	i;
	printf("Executing ft_stash... ");
	if (!stash)
	{
		stash = ft_calloc(stash_size, sizeof(char));
		if (!stash)
			return (0);
		printf("ft_stash malloced successfully\n");
	}
	i = 0;
	printf("Before loop: nl_index: %ld, line[%ld]: %c\n", i, i, line[i]);
	while (i < nl_index && line[i])
	{
		stash[i] = line[i];
		printf("line[i]: %c, stash[i]: %c, i: %ld\n", line[i], stash[i], i);
		i++;
	}
	printf("stash: %s$^$\n", stash);
	return (1);
}

