/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:42:41 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/14 19:42:42 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**erase_tab(char **tab, int j)
{
	j--;
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

static char	*ft_strcpy(char *dest, char *src, char c, size_t *i)
{
	size_t	j;
	size_t	size;

	j = 0;
	size = 0;
	while (src[size + *i] && src[size + *i] != c)
		size++;
	if (!(dest = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (j < size)
	{
		dest[j] = src[*i];
		j++;
		*i += 1;
	}
	dest[j] = '\0';
	while (src[*i] == c && src[*i])
		*i += 1;
	return (dest);
}

static int	word_count(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] == c && str[i])
		i++;
	if (str[i])
		count++;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	if (!(s))
		return (NULL);
	i = word_count((char *)s, c);
	j = 0;
	if (!(tab = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	if (i == 0)
		return (tab);
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_strcpy(tab[j], (char *)s, c, &i);
		if (!(tab[j]))
			return (erase_tab(tab, j));
		j++;
	}
	return (tab);
}
