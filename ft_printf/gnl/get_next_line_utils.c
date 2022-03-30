/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:41:55 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/30 23:22:33 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_g_strlen(const char *s)
{
	const char	*r;

	if (!s)
		return (0);
	r = s;
	while (*r)
		r++;
	return (r - s);
}

char	*ft_g_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*s)
			return (NULL);
		s++;
	}
}

char	*ft_g_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	res = (char *)malloc(++len);
	if (!res)
		return (NULL);
	i = 0;
	if (start <= (unsigned int)ft_g_strlen(s))
	{
		s += start;
		while (--len > 0)
			*(res + i++) = *s++;
	}
	*(res + i) = '\0';
	return (res);
}

int	ft_g_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (dstsize)
	{	
		while (*s && dstsize-- > 1)
			*d++ = *s++;
		*d = '\0';
	}
	return (ft_g_strlen(src));
}

char	*ft_g_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		n;

	if (!s1 && !s2)
		return (NULL);
	len = 1;
	if (s1)
		len += ft_g_strlen(s1);
	if (s2)
		len += ft_g_strlen(s2);
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	n = 0;
	if (s1)
		n = ft_g_strlcpy(res, s1, len);
	if (s2)
		(void)ft_g_strlcpy(res + n, s2, len - n);
	if (s1)
		free(s1);
	s1 = NULL;
	return (res);
}
