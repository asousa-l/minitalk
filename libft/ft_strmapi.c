/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:35:00 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/14 19:49:32 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;

	i = -1;
	dest = ft_strdup(s);
	if (!dest)
		return (NULL);
	while (dest[++i])
		dest[i] = (*f)(i, dest[i]);
	return (dest);
}
