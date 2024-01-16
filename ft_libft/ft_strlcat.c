/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:11:11 by gghaya            #+#    #+#             */
/*   Updated: 2022/11/09 21:27:06 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	dstlen = ft_strlen(dst);
	while (src[i] != '\0' && dstlen + 1 < dstsize)
	{
		dst[dstlen++] = src[i++];
	}
	dst[dstlen] = '\0';
	return (ft_strlen(dst) + ft_strlen(src + i));
}
