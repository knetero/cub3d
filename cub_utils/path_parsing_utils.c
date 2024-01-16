/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:37:29 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/09 18:58:07 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_id_help(t_var *v, int i, int n)
{
	char	*s;
	int		len;

	len = n - v->save;
	while (v->new_map[i][n] && v->new_map[i][n] != '.'
		&& v->new_map[i][n - 1] != 'C' && v->new_map[i][n - 1] != 'F'
		&& v->new_map[i][n] == ' ')
	{
		if (v->new_map[i][n] != ' ')
			return (ft_puterror("Error: in identifiers!\n", 2));
		n++;
	}
	s = ft_substr(v->new_map[i], v->save, len);
	if (ft_strcmp(s, "NO") != 0 && ft_strcmp(s, "SO") != 0
		&& ft_strcmp(s, "WE") != 0 && ft_strcmp(s, "EA") != 0
		&& ft_strcmp(s, "C") != 0 && ft_strcmp(s, "F") != 0)
		return (ft_puterror("Error: in identifiersssssssss!\n", 2), free(s));
	else
		v->flag++;
	free(s);
}

void	is_opened(char *s[])
{
	t_fds	fds;

	fds.fd0 = open(s[0], O_RDONLY);
	fds.fd00 = open(s[0], O_DIRECTORY);
	if (fds.fd0 == -1 || fds.fd00 != -1)
		ft_puterror("Error: Failed to open file path 0\n", 2);
	fds.fd1 = open(s[1], O_RDONLY);
	fds.fd01 = open(s[1], O_DIRECTORY);
	if (fds.fd1 == -1 || fds.fd01 != -1)
		ft_puterror("Error: Failed to open file path 1\n", 2);
	fds.fd2 = open(s[2], O_RDONLY);
	fds.fd02 = open(s[2], O_DIRECTORY);
	if (fds.fd2 == -1 || fds.fd02 != -1)
		ft_puterror("Error: Failed to open file path 2\n", 2);
	fds.fd3 = open(s[3], O_RDONLY | O_RDWR);
	fds.fd03 = open(s[3], O_DIRECTORY);
	if (fds.fd3 == -1 || fds.fd03 != -1)
		ft_puterror("Error: Failed to open file path 3\n", 2);
}

int	is_comma(char **str, int i, int j)
{
	int	flag;

	flag = 0;
	while (str[i][j])
	{
		if (str[i][j] == ',')
			flag++;
		j++;
	}
	if (flag != 2)
		return (1);
	return (0);
}

int	check_digit(char **str, int i, int j)
{
	while (str[i][j] && str[i][j] != ' ')
	{
		while (str[i][j] && str[i][j] != ',' && str[i][j] != ' ')
		{
			if (ft_isdigit(str[i][j]) != 1)
				return (1);
			j++;
		}
		j++;
	}
	return (0);
}

int	check_after_d(char **str, int i, int j)
{
	while (str[i][j] && str[i][j] != ' ')
		j++;
	while (str[i][j])
	{
		if (str[i][j] != ' ')
			return (1);
		j++;
	}
	return (0);
}
