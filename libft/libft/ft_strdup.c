/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:38:55 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/08 11:31:34 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t		length;
	char	*cpy;

	length = ft_strlen(s1);
	if (!(cpy = (char*)malloc(sizeof(cpy) * (length + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
