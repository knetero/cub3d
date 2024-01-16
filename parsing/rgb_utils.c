/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:48:26 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/08 19:39:01 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_num(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_rgb_color(char **rgb)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	r = r << 16;
	g = g << 8;
	color = r + g + b;
	return (color);
}

void	floor_util(t_var *v, char **numbers, char **floor)
{
	if (v->is_floor == 1)
	{
		floor = ft_split(v->s, ',');
		if (count_num(floor) != 3)
		{
			ft_freetab(floor);
			ft_freetab(numbers);
			free(v->s);
			ft_puterror("Error: in rgb numbers\n", 2);
		}
		v->rgb->floor = get_rgb_color(floor);
		ft_freetab(floor);
	}
}

void	ceiling_util(t_var *v, char **numbers, char **ceiling)
{
	if (v->is_floor == 0)
	{
		ceiling = ft_split(v->s, ',');
		if (count_num(ceiling) != 3)
		{
			ft_freetab(ceiling);
			ft_freetab(numbers);
			free(v->s);
			ft_puterror("Error: in rgb numbers\n", 2);
		}
		v->rgb->ceiling = get_rgb_color(ceiling);
		ft_freetab(ceiling);
	}
}

void	rgb_finalparser(t_var *v, char **numbers)
{
	char	**floor;
	char	**ceiling;

	if (v->is_floor == 1)
		floor_util(v, numbers, floor);
	else
		ceiling_util(v, numbers, ceiling);
}
