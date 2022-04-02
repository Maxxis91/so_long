/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:46:11 by gmelissi          #+#    #+#             */
/*   Updated: 2022/04/02 03:21:56 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "../include/so_long.h"

int	render_next_frame(t_data *d)
{
	int	x;
	int	y;

	ft_render_map(d);
	x = d->l * (d->map->w - 3) / 2;
	y = d->h * (d->map->h - 3) / 2;
	if (d->in_game)
	{
		d->_w = mlx_xpm_file_to_image(d->m, "./img/W96.xpm", &(d->l), &(d->h));
		mlx_put_image_to_window(d->m, d->w, d->_w, x, y);
	}
	return (0);
}

int	handle_cross(t_map *map)
{
	ft_clear_map(map);
	exit (0);
}

static void	assign_dir(int keysym, int *i, int *j)
{
	if (keysym == 13)
		*i = -1;
	if (keysym == 0)
		*j = -1;
	if (keysym == 1)
		*i = 1;
	if (keysym == 2)
		*j = 1;
	return ;
}

int	handle_keypress(int keysym, t_data *d)
{
	int	v[2];

	v[0] = 0;
	v[1] = 0;
	assign_dir(keysym, &v[0], &v[1]);
	if (!d->in_game)
		ft_move(d, v);
	if (keysym == 53)
	{
		mlx_destroy_window(d->m, d->w);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	ft_load_init(&d, argc, argv[1]);
	mlx_loop_hook(d.m, &render_next_frame, &d);
	mlx_hook(d.w, 2, 0, &handle_keypress, &d);
	mlx_hook(d.w, 17, 0, &handle_cross, d.map);
	mlx_loop(d.m);
	return (0);
}
