/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:37:48 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/14 16:38:53 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strleng(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int		check_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	return (set[i] == '\0' ? 0 : 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (check_set(s1[i], (char *)set))
		i++;
	size = ft_strleng((char *)s1);
	while (check_set(s1[size - 1], (char *)set) && size > 0)
		size--;
	if (size != 0)
		size -= i;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (j < size)
	{
		str[j] = s1[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
