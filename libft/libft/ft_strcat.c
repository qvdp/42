/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:01:01 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/08 12:15:40 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_strcat(char *restrict s1, char *restrict s2)
{
	size_t	length_s1;
	size_t	length_s2;
	size_t	i;

	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	i = 0;
	while(i < length_s2)
	{
		s1[length_s1 + i] = s2[i];
		i++;
	}
	s1[length_s1 + i] = '\0';
	return (s1);
}
