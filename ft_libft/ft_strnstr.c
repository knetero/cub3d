/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:27:10 by gghaya            #+#    #+#             */
/*   Updated: 2022/10/29 13:02:46 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	i = 0;
	if (!str && !n)
		return (NULL);
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		if (str[i] == to_find[0] && n - i >= ft_strlen(to_find)
			&& ft_strncmp(str + i, to_find, ft_strlen(to_find)) == 0)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
