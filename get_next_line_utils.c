/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/03/03 07:19:30 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (i < size * count)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_line_length(const char *str)
{
	size_t	len;

	len = 0;
	if (!str || !str[len])
		return (0);
	while (str[len])
	{
		if (len > 0)
		{
			if (str[len - 1] == '\n')
				break ;
		}
		len++;
	}
	return (len);
}

char	ft_no_newline_found(char *buffer)
{
	size_t	length;
	size_t	i;

	length = ft_line_length(buffer);
	i = 0;
	while (i < length)
	{
		if (buffer[i++] == '\n')
			return (0);
	}
	return (1);
}

size_t	ft_nl_index(char *buffer)
{
	size_t	line_length;
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
