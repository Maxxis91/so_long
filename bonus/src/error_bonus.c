/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:13:03 by gmelissi          #+#    #+#             */
/*   Updated: 2022/03/30 23:52:26 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_error(int msg)
{
	extern int	errno;

	if (!msg)
		return ;
	if (msg == 9)
		perror("Error\nMap path incorrect");
	if (msg == 2)
		perror("Error\nMap file open failed");
	if (msg == 3)
		perror("Error\nMap file is empty");
	if (msg == 1)
		perror("Error\nMap creation failed");
	if (msg == 8)
		perror("Error\nMLX init failed");
	if (msg == 4)
		perror("Error\nMap not rectangular");
	if (msg == 5)
		perror("Error\nMap not wall-closed");
	if (msg == 6)
		perror("Error\nMap has invalid character");
	if (msg == 7)
		perror("Error\nMap has wrong object count");
	exit(EXIT_FAILURE);
}
