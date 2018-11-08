/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:39:54 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/07 18:49:42 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j])
				j++;
			if (!needle[j])
				return (&haystack[i]);
		}
		i++;
	}
	return NULL;
}
