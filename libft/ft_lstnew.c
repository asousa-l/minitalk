/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:44:03 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/15 10:49:36 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dest;

	dest = (t_list *)malloc(sizeof(*dest));
	if (!dest)
		return (NULL);
	dest->next = NULL;
	dest->content = content;
	return (dest);
}
