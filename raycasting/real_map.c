/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:50:23 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/13 23:30:25 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_real	help2_real(t_var *var, t_struct **s, t_real r)
{
	while (var->new_map[r.i])
	{
		r.tmp = ft_strtrim(var->new_map[r.i], r.set);
		if (ft_strlen(r.tmp) > r.len)
			r.len = ft_strlen(r.tmp);
		free(r.tmp);
		r.i++;
	}
	(*s)->map = NULL;
	(*s)->map = malloc(sizeof(char *) * ((r.i - r.begin) + 2));
	if (!(*s)->map)
		exit(0);
	r.i = 0;
	return (r);
}

t_real	free_real(t_struct **s, t_real r)
{
	(*s)->map[r.i][r.len] = '\0';
	r.i++;
	r.begin++;
	r.k = ft_strlen(r.line);
	ft_bzero(r.line, r.k);
	free(r.line);
	return (r);
}

void	real_map(t_var *var, t_struct **s)
{
	t_real	r;

	r = help_real(var, r);
	r = help2_real(var, s, r);
	while (var->new_map[r.begin])
	{
		r.line = ft_strtrim(var->new_map[r.begin], r.set);
		(*s)->map[r.i] = (char *)malloc(sizeof(char) * (r.len + 1));
		if (!((*s)->map[r.i]))
			exit(0);
		r.j = 0;
		while ((r.j < r.len))
		{
			if (r.j < ft_strlen(r.line) && r.line[r.j]
				&& (ft_strchrr("10NEWS", r.line[r.j]) == 1))
				(*s)->map[r.i][r.j] = r.line[r.j];
			else
				(*s)->map[r.i][r.j] = '1';
			r.j++;
		}
		r = free_real(s, r);
	}
	(*s)->map[r.i] = NULL;
}

void	info_init(t_struct **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*s)->map[i][j])
		j++;
	while ((*s)->map[i])
		i++;
	(*s)->map_rows = i;
	(*s)->map_cols = j;
	(*s)->tail_size = SIZE;
	(*s)->win_width = WIDTH;
	(*s)->img.width = (*s)->win_width;
	(*s)->win_higth = HEIGHT;
	(*s)->img.height = (*s)->win_higth;
	(*s)->fov_angle = 60 * ((M_PI / 2) / 180);
	(*s)->wall_width = 1;
	(*s)->num_rays = ((*s)->win_width / (*s)->wall_width);
	(*s)->delta_x = 0;
	(*s)->delta_y = 0;
}

void	cast_rays(t_struct **s)
{
	int		i;
	int		texture;
	double	ray_ang;
	t_inter	r1;
	t_inter	r2;

	(*s)->rays = malloc(sizeof (t_ray));
	i = 0;
	ray_ang = (*s)->rot_angle - ((*s)->fov_angle / 2);
	while (i < (*s)->num_rays)
	{
		(*s)->rays->ray_angle = normalize(ray_ang);
		*(*s)->rays = is_facing(*(*s)->rays);
		r1 = v_intersect(*(*s)->rays, s);
		r2 = h_intersect(*(*s)->rays, s);
		if (r1.dist <= r2.dist)
			*(*s)->rays = fill_info(r1, *(*s)->rays, 1);
		else
			*(*s)->rays = fill_info(r2, *(*s)->rays, 0);
		texture = check_wall_hit(s, texture, (*s)->rays);
		render_walls(s, i, texture, (*s)->rays);
		i++;
		ray_ang += ((*s)->fov_angle / (double)(*s)->num_rays);
	}
	free((*s)->rays);
}
