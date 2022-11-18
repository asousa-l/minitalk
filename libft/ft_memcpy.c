/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:04:46 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/14 13:24:14 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*a;
	char		*b;

	a = (char *)src;
	b = (char *)dst;
	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	while (n-- > 0)
		*b++ = *a++;
	return (dst);
}
