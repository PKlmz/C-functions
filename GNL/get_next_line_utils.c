/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:29:11 by pkaerts           #+#    #+#             */
/*   Updated: 2021/02/19 19:29:13 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//Ce fichier contient des fonctions aditionnelles utilisées par le fichier principal


void	ft_strdel(char **str)//		Cette fonction sert à libérer la mémoire allouée par malloc une fois obsolète
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

size_t	ft_strlen(char *str)//		Cette fonction mesure la taille  que je dois allouer avec malloc
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strchr(char *str, int c)//	Cette fonction sert à détecter un caractère spécifique dans une chaîne de caractère et renverra un nombre entier correspondant à une case après ce caractère ou 0 si le caractère est absent
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src)//		Cette fonction sert à copier une chaîne de caractère en allouant dynamiquement la mémoire
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!src)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!(dst))
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int c)//	Cette fonction sert à joindre la seconde chaîne de caractères (jusqu'à un caractère spécifique) à la première. Elle agira de façon similaire à un strdup si la deuxième est vide.
{
	size_t	len;//	Variable enregistrant la taille à allouer dynamiquement
	size_t	i;
	size_t	j;
	char	*dst;

	i = -1;
	j = 0;
//	printf("\tCheck join\n"); un test visant à vérifier si j'entre correctement dans la fonction
	if (!s2)
		return (NULL);
	len = ft_strlen(s1);
	while (s2[++i] != (unsigned char)c) //après avoir calculé la taille de la première chaîne je vois combien de caractère de la deuxième je vais avoir besoin de copier
		len++;
	i = 0;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);// Je vérifie si la mémoire à bien été allouée
	while (s1 && s1[i])// Je copie dans la première chaîne
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != (unsigned char)c)// Je copie la seconde chaîne jusqu'au caractère donné en paramètre
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}
