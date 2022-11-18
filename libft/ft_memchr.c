/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:50:54 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/14 14:59:17 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	i = 0;
	str = (const char *)s;
	while (i < n)
	{
		if (str[i] == (const char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
