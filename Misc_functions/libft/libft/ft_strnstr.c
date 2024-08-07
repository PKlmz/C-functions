/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:43:19 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/12 20:43:20 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s2[i] && s2[i] == s1[i] && i < len)
		i++;
	return (s2[i] == '\0' ? 0 : 1);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*s2))
		return ((char *)s1);
	while (i < len)
	{
		if (s1[i] == s2[0])
		{
			if (!(ft_strcmp((char *)s1 + i, s2, len - i)))
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
