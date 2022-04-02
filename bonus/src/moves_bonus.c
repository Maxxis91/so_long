/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:41:34 by gmelissi          #+#    #+#             */
/*   Updated: 2022/04/02 03:26:02 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	ft_move_s(t_data *d, int i, int j, int v[])
{
	d->map->data[i + v[0]][j + v[1]] = 'P';
	if (!d->exit)
		d->map->data[i][j] = '0';
	else
	{
		d->map->data[i][j] = 'E';
		d->exit--;
	}
	ft_printf("Moves: %d\n", ++d->ctr);
	return ;
}

static void	ft_move_c(t_data *d, int i, int j, int v[])
{
	d->map->data[i + v[0]][j + v[1]] = 'P';
	if (!d->exit)
		d->map->data[i][j] = '0';
	else
	{
		d->map->data[i][j] = 'E';
		d->exit--;
	}
	d->map->c--;
	ft_printf("Moves: %d\n", ++d->ctr);
	return ;
}

static void	ft_move_e(t_data *d, int i, int j, int v[])
{
	d->exit++;
	d->map->data[i + v[0]][j + v[1]] = 'P';
	d->map->data[i][j] = '0';
	ft_printf("Moves: %d\n", ++d->ctr);
	if (!d->map->c)
		d->in_game = 1;
	return ;
}

void	ft_move(t_data *d, int v[])
{
	int	i;
	int	j;

	i = -1;
	while (++i < d->map->h)
	{
		j = -1;
		while (++j < d->map->w)
		{
			if (d->map->data[i][j] == 'P')
			{
				if (d->map->data[i + v[0]][j + v[1]] == '0')
					ft_move_s(d, i, j, v);
				if (d->map->data[i + v[0]][j + v[1]] == 'C')
					ft_move_c(d, i, j, v);
				if (d->map->data[i + v[0]][j + v[1]] == 'E')
					ft_move_e(d, i, j, v);
				return ;
			}
		}
	}
}
