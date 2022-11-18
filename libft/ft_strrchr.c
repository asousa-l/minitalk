/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:44:05 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/14 14:45:53 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*s != '\0')
		s++;
	if (c == 0)
		return ((char *)s);
	while (s >= str)
	{
		if (*s == (const char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
