/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:16:40 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/12 20:18:00 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2 || !s1)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) +1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[x])
		str[i++] = s2[x++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != (char )c)
		i++;
	if (s[i] == (char )c)
		return (1);
	return (0);
}
