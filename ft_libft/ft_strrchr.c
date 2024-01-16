/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:51:52 by gghaya            #+#    #+#             */
/*   Updated: 2022/10/29 13:02:55 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	char	ch;
	char	*str;
	int		i;

	str = (char *)string;
	ch = (char)searchedChar;
	i = ft_strlen(string);
	while (i >= 0)
	{
		if (str[i] == ch)
			return (str + i);
		i--;
	}
	return (0);
}
