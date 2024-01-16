/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:22:17 by gghaya            #+#    #+#             */
/*   Updated: 2022/11/06 16:34:42 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	size_t			i;
	unsigned char	*memo;

	i = 0;
	memo = (unsigned char *)str;
	while (i < size)
	{
		if (memo[i] == (unsigned char)c)
			return ((unsigned char *)(str + i));
		i++;
	}
	return (NULL);
}
