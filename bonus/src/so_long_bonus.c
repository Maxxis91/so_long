/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:46:11 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/30 23:52:46 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "../include/so_long_bonus.h"

int	render_next_frame(t_data *d)
{
	ft_render_map(d);
	if (d->in_game)
		mlx_string_put(d->m, d->w, d->l * (d->map->w / 2 - 1) + 3,
			d->h * d->map->h * 0.5, 0x00FF0000, "Winner is you");
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
