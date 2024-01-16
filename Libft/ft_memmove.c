/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:28:15 by abazerou          #+#    #+#             */
/*   Updated: 2022/11/17 14:55:27 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	const char	*psrc;

	pdst = (char *)dst;
	psrc = (const char *)src;
	if (!psrc && !pdst)
		return (NULL);
	if (pdst > psrc)
	{
		while (len > 0)
		{
			len--;
			pdst[len] = psrc[len];
		}
	}
	else
		ft_memcpy(pdst, psrc, len);
	return (pdst);
}
