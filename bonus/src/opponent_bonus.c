/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opponent_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:23:31 by gmelissi          #+#    #+#             */
/*   Updated: 2022/04/03 11:58:07 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	ft_init_opponent(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (++i < d->map->h - 1)
	{
		j = rand() % (d->map->w - 2) + 1;
		if (d->map->data[i][j] == '0')
			d->map->data[i][j] = 'F';
	}
	return ;
}

void	ft_load_opponent(t_data *d)
{
	int	i;

	ft_init_opponent(d);
	d->o_path = (char **)malloc(sizeof(char *) * 4);
	if (!d->o_path)
		ft_error(8);
	d->_o = (void **)malloc(sizeof(void *) * 4);
	if (!d->_o)
		ft_error(8);
	d->o_path[0] = "./img/O32_0.xpm";
	d->o_path[1] = "./img/O32_1.xpm";
	d->o_path[2] = "./img/O32_2.xpm";
	d->o_path[3] = "./img/O32_3.xpm";
	i = -1;
	while (++i < 4)
		d->_o[i] = mlx_xpm_file_to_image(d->m, d->o_path[i], &(d->l), &(d->h));
	return ;
}

void	ft_load_player(t_data *d)
{
	int	i;

	d->p_path = (char **)malloc(sizeof(char *) * 4);
	if (!d->p_path)
		ft_error(8);
	d->_p = (void **)malloc(sizeof(void *) * 4);
	if (!d->_p)
		ft_error(8);
	d->p_path[0] = "./img/Icon32_0.xpm";
	d->p_path[1] = "./img/Icon32_1.xpm";
	d->p_path[2] = "./img/Icon32_2.xpm";
	d->p_path[3] = "./img/Icon32_3.xpm";
	i = -1;
	while (++i < 4)
		d->_p[i] = mlx_xpm_file_to_image(d->m, d->p_path[i], &(d->l), &(d->h));
	return ;
}

void	ft_put_opponent(t_data *d, int i, int j)
{
	int	k;

	k = d->ctr % 4;
	if (d->map->data[i][j] == 'F')
		mlx_put_image_to_window(d->m, d->w, d->_o[k], d->l * j, d->h * i);
	return ;
}
