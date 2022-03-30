/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:27:18 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/28 22:03:37 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_count_lines(const char *path, t_map **ret)
{
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		else
		{
			(*ret)->h++;
			(*ret)->w = ft_strlen(tmp);
			free(tmp);
			tmp = NULL;
		}
	}
	close(fd);
}

static void	ft_load_lines(const char *path, t_map **ret)
{
	int		i;
	int		fd;
	char	*tmp;
	char	**res;

	res = malloc(sizeof(*res) * ((*ret)->h));
	if (!res)
		ft_error(1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(2);
	i = 0;
	while (i < (*ret)->h)
	{
		tmp = get_next_line(fd);
		res[i] = malloc(ft_strlen(tmp));
		if (!res[i])
			ft_error(1);
		ft_strlcpy(res[i], tmp, ft_strlen(tmp) + (i == (*ret)->h - 1));
		i++;
		free(tmp);
		tmp = NULL;
	}
	close(fd);
	(*ret)->data = res;
}

t_map	*ft_load_map(const char *path)
{
	t_map	*ret;

	ret = malloc(sizeof(*ret));
	if (!ret)
		ft_error(1);
	ret->w = 0;
	ret->h = 0;
	ret->c = 0;
	ft_count_lines(path, &ret);
	if (!ret->h)
		ft_error(3);
	ft_load_lines(path, &ret);
	return (ret);
}

void	ft_clear_map(t_map *map)
{
	while (map->h > 0)
	{
		free(map->data[--(map->h)]);
		map->data[map->h] = NULL;
	}
	free(map->data);
	map->data = NULL;
	free(map);
	map = NULL;
}

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	printf("w: %d; h: %d; c: %d\n", map->w, map->h, map->c);
	while (i < map->h)
		printf("|%s|\n", map->data[i++]);
}
