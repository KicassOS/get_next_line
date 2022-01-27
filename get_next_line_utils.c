/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/01/26 16:24:53 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_clear_buffer(char *buffer)
{
	ssize_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i++] = '\0';
	}
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
