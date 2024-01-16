/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:32:40 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/14 19:01:57 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	help_line(t_var *v, char **map)
{
	while (v->s_trim && v->s_trim[0] == '\n')
	{
		v->b++;
		if (!v->s_trim)
			ft_puterror("Error: null\n", 2);
		if (v->s_trim != NULL)
			free(v->s_trim);
		v->s_trim = pure_strtrim(map[v->b], " ");
	}
}

void	skip_space(t_var *v)
{
	while (v->new_map[v->x][v->skip] && v->new_map[v->x][v->skip] == ' ')
		v->skip++;
	v->save = v->skip;
	while (v->new_map[v->x][v->skip] && v->new_map[v->x][v->skip] != ' ')
		v->skip++;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_puterror(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	exit (1);
}
