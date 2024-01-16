/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:28:55 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/15 12:36:40 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	check_dup(char **map, t_var *v)
{
	char	*s;
	int		i;
	int		j;
	int		flag;
	int		f;

	flag = 0;
	f = 0;
	i = 0;
	j = 0;
	while (i < v->map_pos)
	{
		s = pure_strtrim(map[i], " ");
		if (s[j] && (s[j] == 'N' || s[j] == 'S' || s[j] == 'W' || s[j] == 'E'))
			flag++;
		if (s[j] && (s[j] == 'F' || s[j] == 'C'))
			f++;
		free(s);
		i++;
	}
	if (flag > 4)
		ft_puterror("Error: Duplicated path!\n", 2);
	if (f > 2)
		ft_puterror("Error: Duplicated Identifiers!\n", 2);
}

void	check_last_line(char **map, t_var *v)
{
	search_map(map, v);
	v->b = v->i;
	v->s_trim = pure_strtrim(map[v->b], " ");
	while (v->s_trim && map[v->b] != NULL)
	{
		if (v->s_trim && ft_strlen(v->s_trim) == 1 && v->s_trim[0] == '\n')
		{
			help_line(v, map);
			if (!v->s_trim)
				break ;
			if (v->s_trim && (v->s_trim[0] != '\n' && v->s_trim[0] != '\0'))
				ft_puterror("Error: map separated\n", 2);
		}
		else
		{
			v->b++;
			if (v->s_trim != NULL)
				free(v->s_trim);
			v->s_trim = pure_strtrim(map[v->b], " ");
		}
		if (!v->s_trim)
			break ;
	}
	v->i = 0;
}

int	read_map(t_var *v)
{
	v->map = malloc(sizeof(char *) * (v->map_len + 1));
	if (!v->map)
		return (free(v->map), 1);
	while (v->j < v->map_len)
	{
		v->map[v->j] = get_next_line(v->fd);
		v->j++;
	}
	v->map[v->j] = NULL;
	check_last_line(v->map, v);
	v->big_line = get_biggest_line(v->map);
	v->new_map = malloc(sizeof(char *) * (v->map_len + 1));
	if (!v->new_map)
		return (free(v->new_map), 1);
	while (v->map[v->i])
	{
		v->new_map[v->i] = v->map[v->i];
		v->i++;
	}
	free(v->map);
	v->new_map[v->i] = NULL;
	return (0);
}

void	main2(	t_paths	*paths, t_struct *s, t_var v)
{
	v.i = 0;
	parsing(&v, &paths);
	v.i = 0;
	s->ceiling = v.rgb->ceiling;
	s->floor = v.rgb->floor;
	real_map(&v, &s);
	info_init(&s);
	init_player(&s);
	put_pixels(&s, &paths);
	mlx_loop(s->mlx);
	freemap(&s);
	free_all(s, &v);
	free(s);
}

int	main(int ac, char **av)
{
	t_var		v;
	t_info		info;
	t_paths		*paths;
	t_struct	*s;

	if (ac != 2)
		ft_puterror("Error in arguments!\n", 2);
	v.map_len = 0;
	v.big_line = 0;
	v.i = 0;
	v.j = 0;
	s = malloc(sizeof(t_struct));
	paths = my_malloc(sizeof(t_paths), &s);
	v.rgb = my_malloc(sizeof(t_rgb), &s);
	if (!paths || !s || !v.rgb)
		ft_puterror("Error : Failed to allocate structs", 2);
	check_ex(av[1]);
	v.fd = open(av[1], O_RDWR);
	if (v.fd == -1)
		ft_puterror("Error in FILE\n!", 2);
	get_map_len(&v, av[1]);
	if (read_map(&v))
		return (1);
	main2(paths, s, v);
}
