/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:57:33 by gmelissi          #+#    #+#             */
/*   Updated: 2022/04/02 05:27:20 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include "../../ft_printf/ft_printf.h"

typedef struct s_map
{
	int		w;
	int		h;
	int		c;
	char	**data;
}	t_map;

typedef struct s_data
{
	void	*m;
	void	*w;
	t_map	*map;
	void	*_w;
	void	*_s;
	void	*_c;
	void	*_e;
	void	**_p;
	void	**_o;
	char	*w_path;
	char	*s_path;
	char	*c_path;
	char	*e_path;
	char	**p_path;
	char	**o_path;
	int		l;
	int		h;
	int		ctr;
	char	*cctr;
	int		in_game;
	int		exit;
}	t_data;

void	ft_error(int msg);
t_map	*ft_load_map(const char *path);
int		ft_check_map(t_map **map, const char *path);
void	ft_clear_map(t_map *map);
void	ft_load_init(t_data *d, int argc, const char *path);
void	ft_load_opponent(t_data *d);
void	ft_load_player(t_data *d);
void	ft_put_opponent(t_data *d, int i, int j);
void	ft_render_map(t_data *d);

void	ft_move(t_data *d, int v[]);

#endif