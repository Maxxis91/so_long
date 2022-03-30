/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:35:53 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/30 23:24:21 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_check_shape(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->h)
	{
		if (ft_g_strlen(map->data[i++]) != map->w)
			return (1);
	}
	return (0);
}

static int	ft_check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		if (*(map->data[i]) != '1' || *(map->data[i] + map->w - 1) != '1')
			return (1);
		if (!i || i == map->h - 1)
		{
			j = 0;
			while (j < map->w)
			{
				if (map->data[i][j++] != '1')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

static int	ft_check_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (!ft_g_strchr("01CEP", map->data[i][j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_check_obj(t_map *map)
{
	int	e;
	int	p;
	int	i;
	int	j;

	e = 0;
	i = 0;
	p = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			map->c += (map->data[i][j] == 'C');
			e += (map->data[i][j] == 'E');
			p += (map->data[i][j++] == 'P');
		}
		i++;
	}
	if (!(map->c) || !e || p != 1)
		return (7);
	return (0);
}

int	ft_check_map(t_map **map, const char *path)
{
	*map = ft_load_map(path);
	if (ft_check_shape(*map))
		return (4);
	if (ft_check_walls(*map))
		return (5);
	if (ft_check_char(*map))
		return (6);
	return (ft_check_obj(*map));
}
