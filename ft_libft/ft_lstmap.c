/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:08:20 by gghaya            #+#    #+#             */
/*   Updated: 2024/01/12 20:11:26 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*f(void *s)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	while (p[i])
	{
		p[i] = ft_toupper(p[i]);
		i++;
	}
	return (s);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*debut;

	if (!lst)
		return (0);
	debut = NULL;
	while (lst != NULL)
	{
		p = ft_lstnew(f(lst->content));
		if (!p)
		{
			ft_lstclear(&debut, del);
			return (0);
		}
		ft_lstadd_back(&debut, p);
		lst = lst->next;
	}
	return (debut);
}
