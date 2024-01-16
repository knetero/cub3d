/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:15:23 by gghaya            #+#    #+#             */
/*   Updated: 2022/10/29 13:01:16 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int		i;
	char	c;

	c = (char)searchedChar;
	i = 0;
	while (string[i])
	{
		if ((char)string[i] == c)
			return ((char *)string + i);
		i++;
	}
	if (c == '\0')
		return ((char *)string + i);
	return (0);
}
