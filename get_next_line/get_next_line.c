/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:16:28 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/12 20:16:59 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *save, int fd)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (i > 0 && !(ft_strchr(save, '\n')))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i < 0)
		{
			free(buff);
			free(save);
			buff = NULL;
			return (NULL);
		}
		buff[i] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	buff = NULL;
	return (save);
}

char	*first_line(char *save)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (free(save), NULL);
	i = 0;
	while (save[j] && save[j] != '\n')
	{
		res[i++] = save[j++];
	}
	if (save[j] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*left_line(char *save)
{
	char	*res;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	len = ft_strlen(save) - i;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (free(save), NULL);
	while (save[i])
	{
		res[j++] = save[i++];
	}
	res[j] = '\0';
	free(save);
	save = NULL;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_line(save, fd);
	if (!save)
		return (NULL);
	res = first_line(save);
	if (!res || res[0] == '\0')
		return (free(res), NULL);
	save = left_line(save);
	return (res);
}
