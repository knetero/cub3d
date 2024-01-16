/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:27:22 by abazerou          #+#    #+#             */
/*   Updated: 2022/11/17 14:54:42 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rev(char *str)
{
	int		start;
	int		end;
	char	tmp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	return (str);
}

static int	count_num(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				sign;
	int				len;
	int				i;

	sign = 1;
	i = 0;
	len = count_num(n) + 1;
	nb = n;
	if (n < 0)
		nb *= -1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	return (str[i] = '\0', ft_rev(str));
}
