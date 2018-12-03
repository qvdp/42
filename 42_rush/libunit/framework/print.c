/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:48:14 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/02 13:59:54 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libunit.h"

int		ft_strlength(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_pchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_pstrend_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlength(s));
	ft_pchar_fd('\n', fd);
}

void	ft_pstr_fd(char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlength(str));
}

void	ft_pnbr_fd(int n, int fd)
{
	unsigned int abs;

	if (n < 0)
	{
		ft_pchar_fd('-', fd);
		abs = n * -1;
	}
	else
		abs = n;
	if (abs > 9)
		ft_pnbr_fd(abs / 10, fd);
	ft_pchar_fd(abs % 10 + '0', fd);
}
