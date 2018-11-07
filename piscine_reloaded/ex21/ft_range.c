/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:33:30 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/06 14:58:39 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min < max)
	{
		if (!(tab = (int *)malloc(sizeof(*tab) * (max - min))))
			return (0);
		i = 0;
		while (i < max - min)
		{
			tab[i] = min + i;
			i++;
		}
		return (tab);
	}
	else
	{
		tab = 0;
		return (tab);
	}
}
