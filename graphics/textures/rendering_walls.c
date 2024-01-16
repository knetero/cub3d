/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:41:45 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/15 12:33:17 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_sky(t_struct **s, int x, int top_pixel)
{
	int	y;

	y = 0;
	while (y < top_pixel)
	{
		my_mlx_pixel_put(&(*s)->img, x, y, (*s)->ceiling);
		y++;
	}
}

void	draw_floor(t_struct **s, int y, int x)
{
	while (y < ((*s)->win_higth))
	{
		my_mlx_pixel_put(&(*s)->img, x, y, (*s)->floor);
		y++;
	}
}

void	rendr_util(t_struct **s, t_walls *wall, t_ray *ray)
{
	if (ray->distance == 0)
		ray->distance = 1.0;
	wall->correct_dis = ray->distance * cos (ray->ray_angle - (*s)->rot_angle);
	wall->distanceproj = ((*s)->win_width / 2) / tan((*s)->fov_angle / 2);
	wall->pwheight = ((*s)->tail_size / wall->correct_dis) * wall->distanceproj;
	wall->w_stripeheight = (int)wall->pwheight;
	wall->top_pix = ((*s)->win_higth / 2) - (wall->w_stripeheight / 2);
	wall->wbottompx = ((*s)->win_higth / 2) + (wall->w_stripeheight / 2);
}

void	render_walls(t_struct **s, int x, int texture, t_ray *ray)
{
	t_walls	wall;
	int		color;
	int		y;
	int		top_tmp;

	top_tmp = 0;
	rendr_util(s, &wall, ray);
	if (wall.top_pix < 0 || wall.top_pix > (*s)->win_higth)
	{
		top_tmp = wall.top_pix;
		wall.top_pix = 0;
	}
	draw_sky(s, x, wall.top_pix);
	y = wall.top_pix;
	while (y < wall.wbottompx)
	{
		wall.dif = y - wall.top_pix + abs(top_tmp);
		color = get_color(s, texture, wall.w_stripeheight, wall.dif);
		my_mlx_pixel_put(&(*s)->img, x, y, color);
		if (y > (*s)->win_higth)
			break ;
		y++;
	}
	draw_floor(s, y, x);
}
