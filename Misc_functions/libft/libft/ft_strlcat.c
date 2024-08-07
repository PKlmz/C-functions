/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:12:29 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/12 19:12:31 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_total;
	size_t	i;
	size_t	j;

	i = 0;
	size_total = ft_strlen(dst) + ft_strlen(src);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
	{
		j = ft_strlen(dst);
		while (src[i] != '\0' && j < size - 1)
			dst[j++] = src[i++];
		dst[j] = '\0';
		return (size_total);
	}
}
