/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:08:36 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/14 15:41:15 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[a] != '\0')
	{
		b = 0;
		while (str[a + b] == to_find[b] && str[a + b] != '\0' && \
				a + b < len)
		{
			if (to_find[b + 1] == '\0')
				return ((char *)&str[a]);
			b++;
		}
		a++;
	}
	return (NULL);
}
