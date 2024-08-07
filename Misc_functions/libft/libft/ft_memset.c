/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:21:07 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/12 17:23:41 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str2;

	str2 = (unsigned char*)str;
	i = 0;
	while (i < n)
	{
		str2[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
