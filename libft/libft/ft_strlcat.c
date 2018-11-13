/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:13:05 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/12 20:41:06 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict dst, const char *restrict src,
						size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	temp;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size <= i)
		return (j + size);
	k = 0;
	temp = i;
	while (k < (size - temp - 1) && src[k])
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (temp + j);
}
