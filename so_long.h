/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:57:33 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/30 17:18:43 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include "./gnl/get_next_line.h"

# define WIDTH 600
# define HEIGHT 300

# define MLX_ERROR 1

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
	void	*W;
	void	*S;
	void	*C;
	void	*E;
	void	*P;
	char	*W_path;
	char	*S_path;
	char	*C_path;
	char	*E_path;
	char	*P_path;
	int		l;
	int		h;
	int		ctr;
	int		in_game;
	int		exit;
}	t_data;

void	ft_error(int msg);
t_map	*ft_load_map(const char *path);
int		ft_check_map(t_map **map, const char *path);
void	ft_clear_map(t_map *map);
void	ft_load_init(t_data *d, int argc, const char *path);
void	ft_render_map(t_data *d);
void	ft_render_objs(t_data *d);

int ft_move_up(t_data *d);
int ft_move_down(t_data *d);
int ft_move_left(t_data *d);
int ft_move_right(t_data *d);

void	ft_print_map(t_map *map);

#endif