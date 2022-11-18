/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:51:12 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/17 09:31:23 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;

	if (count == 0 || size == 0)
		return (malloc(0));
	dest = malloc(size * count);
	if (!dest)
		return (NULL);
	return (ft_memset((unsigned char *)dest, 0, count * size));
}
