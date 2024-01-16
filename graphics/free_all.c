/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:46:27 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/13 23:28:53 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*my_malloc(size_t size, t_struct **s)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr != NULL && (*s)->alloc_count < MAX_ALLOC)
		(*s)->g_collector[(*s)->alloc_count++] = ptr;
	return (ptr);
}

void	scale_img(t_img *img, int x, int y, t_struct **s)
{
	int	rowy;
	int	colx;
	int	index;
	int	i;

	img->color = my_malloc(sizeof(unsigned int) * (SIZE * SIZE), s);
	if (!img->color)
		ft_puterror("Error : Failed to allocate color", 2);
	y = 0;
	i = 0;
	while (y < SIZE)
	{
		x = 0;
		rowy = ((float)img->height / SIZE) * y;
		while (x < SIZE)
		{
			colx = ((float)img->width / SIZE) * x;
			index = (rowy * img->width + colx);
			img->color[i++] = img->addr[index];
			x++;
		}
		y++;
	}
	img->width = SIZE;
	img->height = SIZE;
}

void	free_all(t_struct *s, t_var *v)
{
	long int	i;

	i = 0;
	while (i < (*s).alloc_count)
	{
		free((*s).g_collector[i]);
		i++;
	}
	ft_free(v->str);
	ft_freetab(v->new_map);
}

void	ft_free(char *s[])
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
}

void	ft_freetab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
