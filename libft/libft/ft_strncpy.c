/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:22:10 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/08 12:00:45 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_strcpy(char *dst, char *src, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
