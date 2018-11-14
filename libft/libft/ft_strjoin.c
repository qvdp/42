/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:10:51 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/14 17:21:53 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	temp;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	if (!(s = (char*)malloc(sizeof(*s) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	temp = i;
	i = 0;
	while (i < ft_strlen(s2))
	{
		s[temp + i] = s2[i];
		i++;
	}
	s[temp + i] = '\0';
	return (s);
}
