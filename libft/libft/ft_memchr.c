/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:26:06 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/12 20:36:55 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_copy;
	size_t			i;

	s_copy = (unsigned char*)s;
	i = 0;
	while (s_copy[i] != (unsigned char)c && i < n && s_copy[i])
		i++;
	if (i == n && s_copy[i] != (unsigned char)c)
		return (NULL);
	else
		return ((unsigned char*)&s_copy[i]);
}
