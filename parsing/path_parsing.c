/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:28:26 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/10 16:55:26 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_path(char *s[], t_paths **paths)
{
	int		index;
	int		i;

	(*paths)->no = NULL;
	(*paths)->so = NULL;
	(*paths)->we = NULL;
	(*paths)->ea = NULL;
	index = 0;
	i = 0;
	while (index < 4)
	{
		i = 0;
		fill_path(s, paths, index, i);
		index++;
	}
}

void	p_validation_help(t_var *v, int i)
{
	while (v->new_map[i][v->n] && v->new_map[i][v->n] != ' ')
	{
		v->n++;
		v->x++;
	}
	while (v->new_map[i][v->n])
	{
		if (v->new_map[i][v->n] != ' ')
			ft_puterror("Error: in path\n", 2);
		v->n++;
	}
}

void	get_path(t_var *v, int i, int j)
{
	get_path_pos(v, i, j);
	if (v->index == 3)
	{
		v->flag = 1;
		return ;
	}
}

void	is_path_valid(t_var *v, t_paths **path)
{
	v->v = 0;
	v->index = 0;
	v->flag = 0;
	while (v->v < v->i)
	{
		v->y = 0;
		v->n = 0;
		v->x = 0;
		while (v->new_map[v->v][v->y] && (v->new_map[v->v][v->y] == ' '
			|| v->new_map[v->v][v->y] == '\t'))
			v->y++;
		if (v->new_map[v->v][v->y] != '\0')
		{
			v->y = 0;
			get_path(v, v->v, v->y);
			if (v->flag == 1)
				break ;
			v->index++;
		}
		v->v++;
	}
	v->index++;
	v->str[v->index] = NULL;
	is_opened(v->str);
	init_path(v->str, path);
}

int	check_id(t_var *v, t_paths **path)
{
	v->x = 0;
	v->i = 0;
	v->flag = 0;
	search_map(v->new_map, v);
	while (v->x < v->i)
	{
		v->y = 0;
		v->n = 0;
		v->skip = 0;
		v->save = 0;
		helper(v);
		if (v->new_map[v->x][v->y] != '\0')
		{
			while (v->new_map[v->x][v->y] && v->new_map[v->x][v->y] != '.')
				v->y++;
			skip_space(v);
			check_id_help(v, v->x, v->skip);
		}
		v->x++;
	}
	if (v->flag < 6)
		return (ft_puterror("Error: identifier is missing!\n", 2), 1);
	is_path_valid(v, path);
	is_rgb_valid(v);
	return (0);
}
