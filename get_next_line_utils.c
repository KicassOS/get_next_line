/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/03/16 05:53:43 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// libft copy-paste
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

// same as in libft but doesn't segfault when the address of  s is NULL
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i])
		i++;
	return (i);
}

// finds char c in s, returning its' position
// flag is used to reduce the number of lines to pass the norm but it's messy
// the -2 return is used to terminate the main loop once EOF is reached
// the -1 is used for the absence of newline, telling gnl to read more
int	ft_strchr_flag(char *s, int c, int flag)
{
	int	i;

	if (flag == 1 && !s)
		return (-2);
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// frees memory and sets pointer address to NULL to prevent potential segfaults
void	ft_free(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

// same as libft, but only copies n chars to prevent segfaults
// used to append the newly read content to the line that has to be returned
char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return (NULL);
	output = malloc(ft_strlen(s1) + n + 1);
	if (!output)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			output[i] = s1[i];
			i++;
		}
	}
	while (s2 && s2[j] && j < n)
		output[i++] = s2[j++];
	output[i] = '\0';
	if (s1)
		ft_free(&s1);
	return (output);
}
