/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:48 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/13 23:28:34 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	init_funct(t_struct **s, t_paths **path)
{
	(*s)->mlx = mlx_init();
	(*s)->win = mlx_new_window((*s)->mlx,
			(*s)->win_width, (*s)->win_higth, "CUB3D");
	read_textures(s, path);
	(*s)->img.img = mlx_new_image((*s)->mlx, (*s)->win_width, (*s)->win_higth);
	(*s)->img.addr = mlx_get_data_addr((*s)->img.img,
			&((*s)->img.bits_per_pixel), &((*s)->img.line_length),
			&((*s)->img.endian));
}

void	put_(t_struct **s)
{
	cast_rays(s);
	mlx_put_image_to_window((*s)->mlx, (*s)->win, (*s)->img.img, 0, 0);
}

void	manage_events(t_struct **s)
{
	mlx_hook((*s)->win, 3, 0, key_released, (s));
	mlx_hook((*s)->win, 2, 0, key_pressed, (s));
	mlx_hook((*s)->win, 17, 0, key_exit, (s));
	mlx_loop_hook((*s)->mlx, &update_info, (s));
}

void	put_pixels(t_struct **s, t_paths **path)
{
	init_funct(s, path);
	manage_events(s);
}
