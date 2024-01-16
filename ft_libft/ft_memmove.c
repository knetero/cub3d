/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:35:22 by gghaya            #+#    #+#             */
/*   Updated: 2022/11/08 19:42:49 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dstt;
	char	*srcc;
	size_t	i;

	dstt = (char *)dest;
	srcc = (char *)src;
	i = 0;
	if (dest != 0 || src != 0)
	{
		if (dstt > srcc)
		{
			while (i < n)
			{
				dstt[n - i - 1] = srcc[n - i - 1];
				i++;
			}
		}
		while (i < n)
		{
			dstt[i] = srcc[i];
			i++;
		}
		return (dstt);
	}
	return (0);
}
