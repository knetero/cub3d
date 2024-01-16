/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:08:04 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/13 18:58:17 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strchrr(const char *string, int searchedChar)
{
	int		i;
	char	c;

	c = (char)searchedChar;
	i = 0;
	while (string[i])
	{
		if ((char)string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_searchc(char *string, char c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1) - 1;
	while (j >= i && ft_searchc((char *)set, s1[j]))
		j--;
	return (ft_substr(s1, i, j - i +1));
}

char	*pure_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_searchc((char *)set, s1[i]))
		i++;
	while (j >= i && ft_searchc((char *)set, s1[j]))
		j--;
	return (ft_substr(s1, i, j - i +1));
}

t_real	help_real(t_var *var, t_real r)
{
	r.line = NULL;
	r.i = 0;
	r.begin = 0;
	r.set = " ";
	r.tmp = pure_strtrim(var->new_map[r.i], r.set);
	while ((var->new_map[r.i][0] != ' ' && var->new_map[r.i][0] != '1' &&
		var->new_map[r.i][0] != '0') ||
		ft_strlen(r.tmp) == 0)
	{
		free(r.tmp);
		r.i++;
		r.tmp = pure_strtrim(var->new_map[r.i], r.set);
	}
	free(r.tmp);
	r.begin = r.i;
	r.tmp = ft_strtrim(var->new_map[r.i], r.set);
	r.len = ft_strlen(r.tmp);
	free(r.tmp);
	r.i++;
	return (r);
}
