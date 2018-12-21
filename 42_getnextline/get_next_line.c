/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:38:10 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/17 16:14:57 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static void		ft_readfd(const int fd, char **str)
{
	int		temp_size;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	while ((temp_size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[temp_size] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
}

static int		return_line(t_gnl *elem, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = elem->line;
	while (elem->line[i] && elem->line[i] != '\n')
		i++;
	*line = (i == 0) ? ft_strnew(0) : ft_strsub(elem->line, 0, i);
	elem->line = (elem->line[i] == '\n') ?
		ft_strdup(ft_strchr(elem->line, '\n') + 1) : ft_strnew(0);
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*list = NULL;
	t_gnl			*tmp;

	if (read(fd, 0, 0) == -1 || BUFF_SIZE < 1)
		return (-1);
	tmp = list;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		if ((tmp = (t_gnl*)malloc(sizeof(t_gnl))))
		{
			tmp->line = ft_strnew(0);
			tmp->fd = fd;
			tmp->next = list;
			list = tmp;
		}
		else
			return (-1);
	}
	if (!(ft_strchr(tmp->line, '\n')))
		ft_readfd(fd, &(tmp->line));
	return ((tmp->line[0]) ? return_line(tmp, line) : 0);
}
