/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:07:43 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/12 20:09:42 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	size_t			i;

	cs = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
		{
			return (cs + i);
		}
		i++;
	}
	return (NULL);
}
