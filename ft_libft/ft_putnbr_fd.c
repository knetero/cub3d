/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:19:11 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/12 20:11:26 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = (long int)n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr <= 9)
	{
		ft_putchar_fd(nbr + '0', fd);
	}
	if (nbr > 9)
	{
		ft_putnbr_fd ((nbr / 10), fd);
		ft_putnbr_fd ((nbr % 10), fd);
	}
}
