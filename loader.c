/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:46:57 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/30 17:18:32 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_map(t_data *d)
{
	int	w;
	int	h;

	d->m = mlx_init();
	if (!d->m)
		ft_error(8);
	d->W_path = "./img/Wall32.xpm";
	d->S_path = "./img/Space32.xpm";
	d->C_path = "./img/Dot32.xpm";
	d->E_path = "./img/Exit32.xpm";
	d->P_path = "./img/Icon32.xpm";
	d->W = mlx_xpm_file_to_image(d->m, d->W_path, &(d->l), &(d->h));
	d->S = mlx_xpm_file_to_image(d->m, d->S_path, &(d->l), &(d->h));
	d->C = mlx_xpm_file_to_image(d->m, d->C_path, &(d->l), &(d->h));
	d->E = mlx_xpm_file_to_image(d->m, d->E_path, &(d->l), &(d->h));
	d->P = mlx_xpm_file_to_image(d->m, d->P_path, &(d->l), &(d->h));
	d->in_game = 1;
	d->exit = 0;
	w = d->l * d->map->w;
	h = d->h * d->map->h;
	d->w = mlx_new_window(d->m, w, h, "./so_long");
	if (!d->w)
		ft_error(8);
	return ;
}

static void	ft_put_tile(t_data *d, int i, int j)
{
	int	w;
	int	h;

	w = d->l * j;
	h = d->h * i;
	if (d->map->data[i][j] == '1')
	{
		if (i && d->map->data[i - 1][j] == '1')
			mlx_put_image_to_window(d->m, d->w, d->W, w, d->h * (i - 0.5));
		mlx_put_image_to_window(d->m, d->w, d->W, w, h);
	}
	else
	{
		if (d->map->data[i][j] == 'E' || (d->map->data[i][j] == 'P' && d->exit))
			mlx_put_image_to_window(d->m, d->w, d->E, w, h);
		else
			mlx_put_image_to_window(d->m, d->w, d->S, w, h);
	}
	if (d->map->data[i][j] == 'C')
		mlx_put_image_to_window(d->m, d->w, d->C, d->l * j, d->h * i);
	if (d->map->data[i][j] == 'P')
		mlx_put_image_to_window(d->m, d->w, d->P, d->l * j, d->h * i);
	return ;
}

void	ft_render_map(t_data *d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < d->map->h)
	{
		j = -1;
		while (++j < d->map->w)
			ft_put_tile(d, i, j);
	}
}

void	ft_load_init(t_data *d, int argc, const char *path)
{	
	if (argc != 2)
		ft_error(9);
	ft_error(ft_check_map(&(d->map), path));
	ft_init_map(d);
	d->ctr = 0;
}
