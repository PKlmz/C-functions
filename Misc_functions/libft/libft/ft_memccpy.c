/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:53:33 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/12 16:54:42 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n && (unsigned char)c != (unsigned char)s[i])
	{
		d[i] = s[i];
		i++;
	}
	if ((unsigned char)c == (unsigned char)s[i] && i < n)
	{
		d[i] = s[i];
		return (d + i + 1);
	}
	return (NULL);
}
