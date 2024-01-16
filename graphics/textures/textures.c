/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:41:58 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/10 15:13:16 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	search_pixel(t_img *img, int w_stripeheight, int wall_dif)
{
	int	color;

	color = 0;
	img->tofy = wall_dif * ((float)img->height / w_stripeheight);
	color = img->color[(img->width * img->tofy) + img->tofx];
	return (color);
}

int	get_horizontal_texture(t_struct **s, t_ray *ray)
{
	int	texture;

	if (ray->facing_down)
	{
		(*s)->no->tofx = ((int)ray->hit_x) % (*s)->no->height;
		texture = 1;
	}
	else
	{
		(*s)->so->tofx = ((int)ray->hit_x) % (*s)->so->height;
		texture = 2;
	}
	return (texture);
}

int	get_vertical_texture(t_struct **s, t_ray *ray)
{
	int	texture;

	if (ray->facing_right)
	{
		(*s)->we->tofx = ((int)ray->hit_y) % (*s)->we->height;
		texture = 4;
	}
	else
	{
		(*s)->ea->tofx = ((int)ray->hit_y) % (*s)->ea->height;
		texture = 3;
	}
	return (texture);
}

void	open_texture(t_img *img, void *mlx, char *path, t_struct **s)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		ft_puterror("Error: mlx_xpm_file_to_image failed !\n", 2);
	img->addr = (unsigned *)mlx_get_data_addr(img->img, &img->bitppixel, \
	&img->line_length, &img->endian);
	if (!img->addr)
		ft_puterror("Error: mlx_get_data_addr failed !\n", 2);
	scale_img(img, 0, 0, s);
}

void	read_textures(t_struct **s, t_paths **path)
{
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;

	no = my_malloc(sizeof(t_img), s);
	if (!no)
		ft_puterror("Error: malloc failed !\n", 2);
	so = my_malloc(sizeof(t_img), s);
	if (!so)
		ft_puterror("Error: malloc failed !\n", 2);
	we = my_malloc(sizeof(t_img), s);
	if (!we)
		ft_puterror("Error: malloc failed !\n", 2);
	ea = my_malloc(sizeof(t_img), s);
	if (!ea)
		ft_puterror("Error: malloc failed !\n", 2);
	open_texture(no, (*s)->mlx, (*path)->no, s);
	open_texture(so, (*s)->mlx, (*path)->so, s);
	open_texture(we, (*s)->mlx, (*path)->we, s);
	open_texture(ea, (*s)->mlx, (*path)->ea, s);
	(*s)->no = no;
	(*s)->so = so;
	(*s)->we = we;
	(*s)->ea = ea;
}
