/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:23:26 by pkaerts           #+#    #+#             */
/*   Updated: 2021/02/19 19:23:28 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	check_rest(char **rest, char **line)
{
	size_t	i;
	char	*tmp;

	i = ft_strchr(*rest, '\n');
	if (i > 0)
	{
		if (i == 1)
			*line = ft_strdup("");
		else
			*line = ft_strjoin_gnl(*line, *rest, '\n');
		tmp = ft_strdup(*rest + i);
		ft_strdel(rest);
		*rest = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(*rest);
	ft_strdel(rest);
	return (2);
}

int	read_line(int fd, char *buffer, char **rest, char **line)
{
	size_t	i;
	size_t	ret;

	ret = 1;
	while (ret > 0)
	{
//		printf("\tCheck read line\n");
		ret = read(fd, buffer, BUFFER_SIZE);
		printf("\tCheck ret : %zu\n", i);
		if (ret > BUFFER_SIZE)
			return (0);
		if (ret < 1)
			return (ret);
		buffer[ret] = '\0';
		i = ft_strchr(buffer, '\n');
//		printf("\tCheck 1\n");
//		printf("\tCheck buffer: %s\n", buffer);	
//		printf("\tCheck line: %s\n", *line);	
//		printf("\tCheck i: %zu\n", i);	
		if (i)
		{
//			printf("\tCheck\n");
			*line = ft_strjoin_gnl(*line, buffer, '\n');
			if (buffer[i])
				*rest = ft_strdup(buffer + i);
			return (1);
		}
		*line = ft_strjoin_gnl(*line, buffer, '\0');
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*rest;
	int			ret;

	ret = 2;
	if (fd < 0 || read(fd, buffer, 0) == -1 || fd > OPEN_MAX)
		return (-1);
//	printf("\tCheck rest: %s\n", rest);
	if (rest && ret > 1)
		ret = check_rest(&rest, line);
	while (ret > 1)
	{
		ret = read_line(fd, buffer, &rest, line);
	}
	if (!*line)
		*line = ft_strdup("");
	return (ret);
}


int		main(void)
{
	int     fd = open("text2.txt",O_RDONLY);
	char    *line = NULL;
	int 	line_nbr = 1;
	int 	 nb;

	while ((nb = get_next_line(fd, &line)) >= 0)
	{
		printf("Ligne %d : %s\n", line_nbr, line);
		ft_strdel(&line);
		line_nbr++;
		if (nb == 0)
			break;
	}
	return 0;
}
