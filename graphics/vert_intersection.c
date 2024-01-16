/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:04 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/13 23:31:53 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_point	init_point(t_point p, t_ray ray, t_struct **s)
{
	p.dist = 1e30;
	p.x = 0;
	p.y = 0;
	p.x_intercept = 0;
	p.y_intercept = 0;
	p.x_intercept = floor ((*s)->player_x / (*s)->tail_size) * (*s)->tail_size;
	if (ray.facing_right)
		p.x_intercept += (*s)->tail_size;
	p.y_intercept = (*s)->player_y + (double)(p.x_intercept - (*s)->player_x)
		*(double)tan(ray.ray_angle);
	p.x_step = (*s)->tail_size;
	if (ray.facing_left)
		p.x_step *= (-1);
	p.y_step = p.x_step * (double)tan(ray.ray_angle);
	if (ray.facing_up && p.y_step > 0)
		p.y_step *= (-1);
	if (ray.facing_down && p.y_step < 0)
		p.y_step *= (-1);
	p.next_x = p.x_intercept;
	p.next_y = p.y_intercept;
	return (p);
}

int	in_map(t_point p, t_struct **s)
{
	if (((int)(p.next_x / (*s)->tail_size) >= 0)
		&& ((int)(p.next_x / (*s)->tail_size) < (*s)->map_cols)
			&& ((int)(p.next_y / (*s)->tail_size) >= 0)
			&& (int)(p.next_y / (*s)->tail_size) < (*s)->map_rows)
		return (1);
	else
		return (0);
}

t_inter	fill_vert(t_inter	interv, t_point p, t_struct **s)
{
	interv.x = p.next_x;
	interv.y = p.next_y;
	interv.dist = distance ((*s)->player_x, (*s)->player_y, interv.x, interv.y);
	return (interv);
}

t_inter	v_intersect(t_ray ray, t_struct **s)
{
	t_inter	interv;
	t_point	p;

	p = init_point(p, ray, s);
	while (in_map(p, s) == 1)
	{
		p.x_check = p.next_x;
		if (ray.facing_left)
			p.x_check--;
		if (wall_check(p.x_check, p.next_y, s) == 1)
		{
			interv = fill_vert(interv, p, s);
			return (interv);
		}
		else
		{
			p.next_x += p.x_step;
			p.next_y += p.y_step;
		}
	}
	interv = fill_vert(interv, p, s);
	return (interv);
}

t_ray	is_facing(t_ray ray)
{
	if (ray.ray_angle > 0 && ray.ray_angle < M_PI)
		ray.facing_down = 1;
	else
		ray.facing_down = 0;
	ray.facing_up = !ray.facing_down;
	if (ray.ray_angle < (0.5 * M_PI) || ray.ray_angle > (1.5 * M_PI))
		ray.facing_right = 1;
	else
		ray.facing_right = 0;
	ray.facing_left = !ray.facing_right;
	return (ray);
}
