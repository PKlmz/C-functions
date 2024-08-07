/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:24:28 by pkaerts           #+#    #+#             */
/*   Updated: 2021/02/19 19:24:31 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Ce fichier.h fait le lien entre mes fichiers.c

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 5	//Cette ligne définissant la nombre caractères que la fonction open lira en une fois est à mettre en commentaire quand le programme est lancé avec la commande officielle, mais il est plus simple de modifier la valeur ici quand il s'agit de faire de simples tests
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
size_t	ft_strchr(char *str, int c);
char	*ft_strdup(char *src);
char	*ft_strjoin_gnl(char *s1, char *s2, int c);
void	ft_strdel(char **str);

#endif
