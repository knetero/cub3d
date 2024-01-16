/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:10:46 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/13 23:24:29 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_pressed(int key_code, t_struct **s)
{
	if (key_code == 53)
		exit(0);
	else if (key_code == W)
		(*s)->delta_y = 1;
	else if (key_code == A)
		(*s)->delta_x = -1;
	else if (key_code == S)
		(*s)->delta_y = -1;
	else if (key_code == D)
		(*s)->delta_x = 1;
	else if (key_code == 123)
		(*s)->turn_dirct = -1;
	else if (key_code == 124)
		(*s)->turn_dirct = 1;
	return (0);
}

int	key_released(int key_code, t_struct **s)
{
	if (key_code == A)
		(*s)->delta_x = 0;
	if (key_code == W)
		(*s)->delta_y = 0;
	else if (key_code == S)
		(*s)->delta_y = 0;
	else if (key_code == D)
		(*s)->delta_x = 0;
	else if (key_code == 123)
		(*s)->turn_dirct = 0;
	else if (key_code == 124)
		(*s)->turn_dirct = 0;
	return (0);
}

int	key_exit(int key_code, t_info *info)
{
	(void)info;
	(void)key_code;
	exit(0);
	return (0);
}

int	wall_collision(double x, double y, t_struct **s)
{
	int	xx;
	int	yy;

	xx = floor(x / (*s)->tail_size);
	yy = floor(y / (*s)->tail_size);
	if (xx < 0 || xx >= ((*s)->map_cols - 1)
		|| yy < 0 || yy >= ((*s)->map_rows - 1))
		return (1);
	if (!(*s)->map[yy] || (*s)->map[yy][xx] == 0 || (*s)->map[yy][xx] == '1')
		return (1);
	return (0);
}

int	wall_check(double x, double y, t_struct **s)
{
	int	xx;
	int	yy;

	xx = floor((x / (*s)->tail_size));
	yy = floor((y / (*s)->tail_size));
	if (xx < 0 || xx >= ((*s)->map_cols)
		|| yy < 0 || yy >= ((*s)->map_rows))
		return (1);
	if ((*s)->map[yy][xx] == '1')
		return (1);
	return (0);
}
