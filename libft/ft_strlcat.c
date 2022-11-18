/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:55:20 by asousa-l          #+#    #+#             */
/*   Updated: 2022/03/07 12:24:00 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dc;
	size_t	sc;

	dc = ft_strlen(dst);
	sc = ft_strlen((char *)src);
	if (dstsize <= dc)
		return (dstsize + sc);
	i = 0;
	while (src[i] != '\0' && dstsize > (dc + 1))
	{
		dst[dc] = src[i];
		i++;
		dc++;
	}
	dst[dc] = '\0';
	return (dc + ft_strlen((char *)(&src[i])));
}
