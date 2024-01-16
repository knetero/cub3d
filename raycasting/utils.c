/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:00:03 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/14 18:08:04 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	distance(double xb, double yb, double xe, double ye)
{
	return (sqrt((xe - xb) * (xe - xb) + (ye - yb) * (ye - yb)));
}

void	init_player(t_struct **s)
{
	int	i;
	int	j;

	i = 0;
	while ((*s)->map[i])
	{
		j = 0;
		while ((*s)->map[i][j])
		{
			if (ft_strchrr("WSEN", (*s)->map[i][j]))
				ft_direction(s, j, i);
			j++;
		}
		i++;
	}
	(*s)->player_x = ((*s)->x * (*s)->tail_size) + (*s)->tail_size / 2;
	(*s)->player_y = ((*s)->y * (*s)->tail_size) + (*s)->tail_size / 2;
	(*s)->real_y = (*s)->y * (*s)->tail_size;
	(*s)->real_x = (*s)->x * (*s)->tail_size;
	(*s)->turn_dirct = 0;
	(*s)->walk_dirct = 0;
	(*s)->move_speed = 15.0;
	(*s)->rot_speed = 3 * (M_PI / 180);
}

void	ft_direction(t_struct **s, int j, int i)
{
	(*s)->x = j;
	(*s)->y = i;
	if ((*s)->x > 0 && (*s)->x < (*s)->map_rows
		&& (*s)->y > 0 && (*s)->y < (*s)->map_cols)
	{
		if ((*s)->map[(*s)->y][(*s)->x] == 'E')
			(*s)->rot_angle = M_PI;
		else if ((*s)->map[(*s)->y][(*s)->x] == 'N')
			(*s)->rot_angle = M_PI_2;
		else if ((*s)->map[(*s)->y][(*s)->x] == 'W')
			(*s)->rot_angle = 0;
		else if ((*s)->map[(*s)->y][(*s)->x] == 'S')
			(*s)->rot_angle = M_PI * 3 / 2;
	}
}

void	norm(t_struct **s)
{
	(*s)->rot_angle = fmod((*s)->rot_angle, 2 * M_PI);
	if ((*s)->rot_angle < 0)
		(*s)->rot_angle += 2 * M_PI;
}

double	normalize(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
