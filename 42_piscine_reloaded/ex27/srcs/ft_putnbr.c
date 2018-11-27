/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:57:20 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/07 15:15:29 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_putnbr(int nb)
{
	unsigned int abs;

	if (nb < 0)
	{
		abs = nb * -1;
		ft_putchar('-');
	}
	else
		abs = nb;
	if (abs > 9)
		ft_putnbr(abs / 10);
	ft_putchar((abs % 10) + '0');
}
