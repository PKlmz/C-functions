/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:46:47 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/12 17:47:08 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)str;
	while (str[i])
	{
		if (str[i] == c)
			j = i;
		i++;
	}
	if (str[j] == c)
		return (s + j);
	else if (str[i] == c)
		return (s + i);
	return (NULL);
}
