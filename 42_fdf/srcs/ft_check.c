/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:02:58 by qvan-der          #+#    #+#             */
/*   Updated: 2019/10/15 22:18:27 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_check_line_content(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		while (ft_isspace(line[i]))
			line++;
		while (!ft_isspace(line[i]) && line[i] != '\0')
		{
			if (!ft_atoi(line) && line[i] != '0' && line[i + 1] != '0')
			{
				ft_putendl_fd(E_FILE_CONTENT, 2);
				return (-1);
			}
			line += (ft_atoi(line) / 10 || 1);
		}
	}
	return (0);
}

int			ft_check_file_content(char *from_path)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(from_path, O_RDONLY)) == -1)
		return (-1);
	ret = ft_get_next_line(fd, &line);
	if (ft_check_line_content(line) == -1)
		return (-1);
	ft_strdel(&line);
	if (ret == 0 || ret == -1)
	{
		ft_putendl_fd(E_FILE_READ, 2);
		return (-1);
	}
	while (ft_get_next_line(fd, &line))
	{
		if (ft_check_line_content(line) == -1)
			return (-1);
		ft_strdel(&line);
	}
	return (close(fd));
}

int			ft_check_file_lines(char *from_path)
{
	int		fd;
	int		line_length;
	char	*line;
	char	**split;

	if ((fd = open(from_path, O_RDONLY)) == -1)
		return (-1);
	ft_get_next_line(fd, &line);
	split = ft_strsplit(line, ' ');
	line_length = (int)ft_arrlen(split);
	ft_freearr(split);
	ft_strdel(&line);
	while (ft_get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		ft_strdel(&line);
		if ((int)ft_arrlen(split) != line_length)
		{
			ft_putendl_fd(E_FILE_CONTENT, 2);
			return (-1);
		}
		ft_freearr(split);
	}
	return (close(fd));
}

int			ft_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd(E_ARGUMENTS, 2);
		return (-1);
	}
	if (ft_check_file_content(argv[1]) == -1)
		return (-1);
	if (ft_check_file_lines(argv[1]) == -1)
		return (-1);
	return (0);
}
