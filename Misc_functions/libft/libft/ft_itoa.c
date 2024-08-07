/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:41:51 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/18 16:41:54 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_addnbr(int nb, char *str, int i)
{
	unsigned int n;

	if (nb < 0)
	{
		str[0] = '-';
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_addnbr(n / 10, str, i - 1);
		n %= 10;
	}
	n += '0';
	str[i] = n;
}

char		*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = 1;
	while (n >= size || n <= -size)
	{
		i++;
		if (size >= 1000000000 || size <= -1000000000)
		{
			i = 10;
			break ;
		}
		size *= 10;
	}
	if (n == 0)
		i = 1;
	if (n < 0)
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_addnbr(n, str, i - 1);
	str[i] = '\0';
	return (str);
}
