/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:08:17 by gmelissi          #+#    #+#             */
/*   Updated: 2022/04/02 05:28:38 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free2(char *s1, char *s2)
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
	if (s2)
		free(s2);
	s2 = NULL;
	return (res);
}