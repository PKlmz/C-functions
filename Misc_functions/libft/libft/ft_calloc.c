/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:31:39 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/19 16:31:43 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = malloc(size * nitems)))
		return (NULL);
	while (i < nitems * size)
	{
		s[i] = 0;
		i++;
	}
	return ((void *)s);
}
