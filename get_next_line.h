/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:59 by pszleper          #+#    #+#             */
/*   Updated: 2022/03/14 04:37:35 by pszleper         ###   ########.fr       */
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
char	*ft_update_nl_pos(char **line, int position);
char	*ft_output(char **line, int position, int bytes_read);
char	*ft_strndup(char *input, int n);

//get_next_line_utils.c
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *s);
int		ft_strchr_flag(char *s, int c, int flag);
void	ft_free(char **p);
char	*ft_strnjoin(char *s1, char *s2, int n);

#endif
