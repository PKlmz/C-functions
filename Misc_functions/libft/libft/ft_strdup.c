/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:43:58 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/19 16:44:01 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	while (!(s = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
