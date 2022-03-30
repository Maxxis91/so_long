/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:33:40 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/18 23:11:05 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_zprec(t_seq *seq, char *s)
{
	char	*res;
	long	len;

	len = ft_smax(seq->prcsn, ft_strlen(s));
	if (seq->flags->x)
		len += 2;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, len + 1);
	(void)ft_memset(res, 48, len);
	(void)ft_strlcpy(res + len - ft_strlen(s), s, ft_strlen(s) + 1);
	if (seq->flags->x)
		*(res + 1) = 120;
	free(s);
	return (res);
}

static char	*ft_get_pad(t_seq *seq, char *s)
{
	char	*res;

	res = (char *)malloc(seq->width + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, seq->width + 1);
	(void)ft_memset(res, 32, seq->width);
	if (seq->flags->ladj)
		(void)ft_strncpy(res, s, ft_strlen(s));
	else
		(void)ft_strncpy(res + seq->width - ft_strlen(s), s, ft_strlen(s) + 1);
	free(s);
	return (res);
}

void	*ft_set_p(t_seq *seq, void *p)
{
	char	*tmp;
	char	*zprec;
	char	*res;

	if (!p)
	{
		if (!seq->prcsn)
			tmp = ft_strdup("");
		else
			tmp = ft_htoa(0);
	}
	else
		tmp = ft_htoa((size_t)p);
	if (seq->flags->ladj)
		seq->flags->zpad = 0;
	seq->flags->x = 1;
	seq->prcsn = ft_strlen(tmp);
	zprec = ft_get_zprec(seq, tmp);
	seq->width = ft_smax(seq->width, ft_strlen(zprec));
	res = ft_get_pad(seq, zprec);
	seq->data = res;
	return (res);
}
