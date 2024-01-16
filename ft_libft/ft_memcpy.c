/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:36:24 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/12 20:17:37 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstt;
	unsigned char	*srcc;
	size_t			i;

	dstt = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	if (dst != 0 || src != 0)
	{
		while (i < n)
		{
			dstt[i] = srcc[i];
			i++;
		}
		return (dstt);
	}
	return (0);
}
