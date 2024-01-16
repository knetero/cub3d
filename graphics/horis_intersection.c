/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horis_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:01 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/13 23:29:39 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_point	init_h_point(t_point p, t_ray ray, t_struct **s)
{
	p.dist = 1e30;
	p.x = 0;
	p.y = 0;
	p.x_intercept = 0;
	p.y_intercept = 0;
	p.y_intercept = floor ((*s)->player_y
			/ (*s)->tail_size) * (*s)->tail_size;
	if (ray.facing_down)
		p.y_intercept += (*s)->tail_size;
	p.x_intercept = (*s)->player_x + (double)(p.y_intercept - (*s)->player_y)
		/ (double)tan(ray.ray_angle);
	p.y_step = (*s)->tail_size;
	if (ray.facing_up)
		p.y_step *= (-1);
	p.x_step = p.y_step / (double)tan(ray.ray_angle);
	if (ray.facing_left && p.x_step > 0)
		p.x_step *= (-1);
	if (ray.facing_right && p.x_step < 0)
		p.x_step *= (-1);
	p.next_x = p.x_intercept;
	p.next_y = p.y_intercept;
	return (p);
}

t_inter	fill_horis(t_inter	interv, t_point p, t_struct **s)
{
	interv.x = p.next_x;
	interv.y = p.next_y;
	interv.dist = distance ((*s)->player_x, (*s)->player_y, interv.x, interv.y);
	return (interv);
}

t_inter	h_intersect(t_ray ray, t_struct **s)
{
	t_inter	interh;
	t_point	p;

	p = init_h_point(p, ray, s);
	while (in_map(p, s) == 1)
	{
		p.y_check = p.next_y;
		if (ray.facing_up)
			p.y_check--;
		if (wall_check(p.next_x, p.y_check, s) == 1)
		{
			interh = fill_horis(interh, p, s);
			return (interh);
		}
		else
		{
			interh.hit_h = false;
			p.next_x += p.x_step;
			p.next_y += p.y_step;
		}
	}
	interh = fill_horis(interh, p, s);
	return (interh);
}

int	update_info( t_struct **s)
{
	double	x_steps;
	double	y_steps;

	(*s)->rot_angle += (*s)->turn_dirct * (*s)->rot_speed;
	norm(s);
	x_steps = (*s)->delta_x * (*s)->move_speed;
	y_steps = (*s)->delta_y * (*s)->move_speed;
	(*s)->real_x = (*s)->player_x + (y_steps * cos((*s)->rot_angle));
	(*s)->real_y = (*s)->player_y + (y_steps * sin((*s)->rot_angle));
	if (wall_collision((*s)->real_x, (*s)->real_y, s) == 0)
	{
		(*s)->player_x = (*s)->real_x;
		(*s)->player_y = (*s)->real_y;
	}
	(*s)->real_x = (*s)->player_x - (x_steps * (sin((*s)->rot_angle)));
	(*s)->real_y = (*s)->player_y + (x_steps * (cos((*s)->rot_angle)));
	if (wall_collision((*s)->real_x, (*s)->real_y, s) == 0)
	{
		(*s)->player_x = (*s)->real_x;
		(*s)->player_y = (*s)->real_y;
	}
	mlx_clear_window((*s)->mlx, (*s)->win);
	put_(s);
	return (0);
}

t_ray	fill_info(t_inter r1, t_ray ray, int vert)
{
	ray.distance = r1.dist;
	ray.hit_x = r1.x;
	ray.hit_y = r1.y;
	ray.hit_vertical = vert;
	return (ray);
}
