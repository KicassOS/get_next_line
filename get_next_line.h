/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:59 by pszleper          #+#    #+#             */
/*   Updated: 2022/02/21 04:31:07 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

// get_next_line.c
char	*get_next_line(int fd);
char	*ft_read_until_newline(char *buffer);
char	ft_stash(char *stash, char *line, ssize_t stash_size, ssize_t nl_index);

//get_next_line_utils.c
size_t	ft_line_length(const char *str);
char	ft_no_newline_found(char *buffer);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_nl_index(char *buffer);

#endif