/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:42:04 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/07 15:12:50 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_header.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[11];

	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		while ((ret = read(fd, buf, 10)))
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		if (close(fd) == -1)
			return (0);
	}
	return (0);
}
