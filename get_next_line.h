/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:59 by pszleper          #+#    #+#             */
/*   Updated: 2022/01/26 16:24:59 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

// get_next_line.c
char	*get_next_line(int fd);
ssize_t	ft_read_until_newline(char *buffer);

//get_next_line_utils.c
size_t	ft_line_length(const char *str);
void	ft_clear_buffer(char *buffer);

#endif