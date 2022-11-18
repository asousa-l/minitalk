/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:20:33 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/14 18:23:32 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		a;
	int		b;
	char	*s;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = -1;
	s = (char *)malloc(sizeof(char) * (a + b + 1));
	if (!s)
		return (NULL);
	while (++i < a)
		s[i] = s1[i];
	i--;
	while (++i - a < b)
		s[i] = s2[i - a];
	s[i] = '\0';
	return (s);
}
