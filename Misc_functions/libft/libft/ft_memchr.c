/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:57:01 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/12 16:58:20 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char*)str;
	i = 0;
	while (i < n && (unsigned char)c != (unsigned char)s[i] && s[i])
		i++;
	if ((unsigned char)c == (unsigned char)s[i] && i < n)
		return (s + i);
	return (NULL);
}
