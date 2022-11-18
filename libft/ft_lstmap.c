/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:33:48 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/15 11:35:16 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*a;
	t_list	*start;

	if (lst)
	{
		a = lst;
		start = ft_lstnew(f(a->content));
		if (!start)
			return (NULL);
		a = a->next;
		while (a != (void *)0)
		{
			new = ft_lstnew(f(a->content));
			if (!new)
			{
				ft_lstclear(&start, del);
				return (NULL);
			}
			ft_lstadd_back(&start, new);
			a = a->next;
		}
		return (start);
	}
	return (NULL);
}
