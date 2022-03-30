/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:41:34 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/30 17:19:58 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_move_up(t_data *d)
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
				if(d->map->data[i - 1][j] == '0')
				{
					d->map->data[i - 1][j] = 'P';
					if (!d->exit)
						d->map->data[i][j] = '0';
					else
					{
						d->map->data[i][j] = 'E';
						d->exit--;
					}
					return (1);
				}
				if(d->map->data[i - 1][j] == 'C')
				{
					d->map->data[i - 1][j] = 'P';
					if (!d->exit)
						d->map->data[i][j] = '0';
					else
					{
						d->map->data[i][j] = 'E';
						d->exit--;
					}
					d->map->c--;
					return (1);
				}
				if(d->map->data[i - 1][j] == 'E')
				{
					d->exit++;
					d->map->data[i - 1][j] = 'P';
					d->map->data[i][j] = '0';
					return (1);
				}
			}
		}
	}
	return (0);
}

int ft_move_down(t_data *d)
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
				if(d->map->data[i + 1][j] == '0')
				{
					d->map->data[i + 1][j] = 'P';
					if (!d->exit)
						d->map->data[i][j] = '0';
					else
					{
						d->map->data[i][j] = 'E';
						d->exit--;
					}
					return (1);
				}
				if(d->map->data[i + 1][j] == 'C')
				{
					d->map->data[i + 1][j] = 'P';
					if (!d->exit)
						d->map->data[i][j] = '0';
					else
					{
						d->map->data[i][j] = 'E';
						d->exit--;
					}
					d->map->c--;
					return (1);
				}
				if(d->map->data[i + 1][j] == 'E')
				{
					d->exit++;
					d->map->data[i + 1][j] = 'P';
					d->map->data[i][j] = '0';
					return (1);
				}
			}
		}
	}
	return (0);
}

int ft_move_left(t_data *d)
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
				if(d->map->data[i][j - 1] == '0')
				{
					d->map->data[i][j - 1] = 'P';
					if (!d->exit)
						d->map->data[i][j] = '0';
					else
					{
						d->map->data[i][j] = 'E';
						d->exit--;
					}
					return (1);
				}
				if(d->map->data[i][j - 1] == 'C')
				{
					d->map->data[i][j - 1] = 'P';
					if (!d->exit)
						d->map->data[i][j] = '0';
					else
					{
						d->map->data[i][j] = 'E';
						d->exit--;
					}
					d->map->c--;
					return (1);
				}
				if(d->map->data[i][j - 1] == 'E')
				{
					d->exit++;
					d->map->data[i][j - 1] = 'P';
					d->map->data[i][j] = '0';
					return (1);
				}
			}
		}
	}
	return (0);
}

int ft_move_right(t_data *d)
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
				if(d->map->data[i][j + 1] == '0')
				{
					d->map->data[i][j + 1] = 'P';
					if (!d->exit)
						d->map->data[i][j] = '0';
					else
					{
						d->map->data[i][j] = 'E';
						d->exit--;
					}
					return (1);
				}
				if(d->map->data[i][j + 1] == 'C')
				{
					d->map->data[i][j + 1] = 'P';
					if (!d->exit)
						d->map->data[i][j] = '0';
					else
					{
						d->map->data[i][j] = 'E';
						d->exit--;
					}
					d->map->c--;
					return (1);
				}
				if(d->map->data[i][j + 1] == 'E')
				{
					d->exit++;
					d->map->data[i][j + 1] = 'P';
					d->map->data[i][j] = '0';
					return (1);
				}
			}
		}
	}
	return (0);
}
