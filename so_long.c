/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:46:11 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/30 17:26:13 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"

int	render_next_frame(void *data)
{
	ft_render_map(data);
//calculate player's position
//remove collectibles when eaten
//render movements counter
//exit when !c && pos == exit
	return (0);
}

int	handle_cross(t_map *map)
{
	ft_print_map(map);
	ft_clear_map(map);
	exit (0);
}

int	handle_keypress(int keysym, t_data *d)
{
	if (keysym == 13)
	{
		if(ft_move_up(d))
			printf("Moves: %d\n", ++d->ctr);
	}
	if (keysym == 0)
	{
		if (ft_move_left(d))
			printf("Moves: %d\n", ++d->ctr);
	}
	if (keysym == 1)
	{
		if (ft_move_down(d))
			printf("Moves: %d\n", ++d->ctr);
	}
	if (keysym == 2)
	{
		if (ft_move_right(d))
			printf("Moves: %d\n", ++d->ctr);
	}
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
