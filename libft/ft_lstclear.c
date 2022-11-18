/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:27:12 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/15 11:30:30 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	a = *lst;
	while (a != (void *)0)
	{
		b = a->next;
		ft_lstdelone(a, del);
		a = b;
	}
	*lst = NULL;
}
