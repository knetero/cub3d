/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:27:07 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/10 16:54:57 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_path_pos(t_var *v, int i, int j)
{
	int	found;

	found = 0;
	while (i < v->i)
	{
		j = 0;
		while (v->new_map[i] && v->new_map[i][j])
		{
			if (v->new_map[i][j] == '/')
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 1)
			break ;
		i++;
	}
	j++;
	v->v = i;
	v->n = j;
	p_validation_help(v, i);
	v->str[v->index] = ft_substr(v->new_map[i], j, v->x);
}

void	fill_path(char *s[], t_paths **paths, int index, int i)
{
	while (s[index][i])
	{
		if ((s[index][i] == 'N' || s[index][i] == 'n')
			&& (s[index][i + 1] == 'O' || s[index][i + 1] == 'o'))
			(*paths)->no = s[index];
		else if ((s[index][i] == 'S' || s[index][i] == 's')
			&& (s[index][i + 1] == 'O' || s[index][i + 1] == 'o'))
			(*paths)->so = s[index];
		else if ((s[index][i] == 'W' || s[index][i] == 'w')
			&& (s[index][i + 1] == 'E' || s[index][i + 1] == 'e'))
			(*paths)->we = s[index];
		else if ((s[index][i] == 'E' || s[index][i] == 'e')
			&& (s[index][i + 1] == 'A' || s[index][i + 1] == 'a'))
			(*paths)->ea = s[index];
		i++;
	}
}

int	get_color(t_struct **s, int texture, int wheight, int wall_dif)
{
	int	color;

	color = 0;
	if (texture == 1)
		color = search_pixel((*s)->no, wheight, wall_dif);
	else if (texture == 2)
		color = search_pixel((*s)->so, wheight, wall_dif);
	else if (texture == 3)
		color = search_pixel((*s)->ea, wheight, wall_dif);
	else if (texture == 4)
		color = search_pixel((*s)->we, wheight, wall_dif);
	return (color);
}

void	helper(t_var *v)
{
	while (v->new_map[v->x][v->y] && (v->new_map[v->x][v->y] == ' '
		|| v->new_map[v->x][v->y] == '\t'))
		v->y++;
}

int	check_wall_hit(t_struct **s, int texture, t_ray *ray)
{
	if (ray->hit_vertical == 1)
		texture = get_vertical_texture(s, ray);
	else
		texture = get_horizontal_texture(s, ray);
	return (texture);
}
