/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:38:41 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/30 23:22:54 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef UINT_MAX
#  define UINT_MAX 4294967295
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_g_strlen(const char *s);
char	*ft_g_strchr(const char *s, int c);
char	*ft_g_substr(const char *s, unsigned int start, size_t len);
int		ft_g_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_g_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
