/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:35:50 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/08 12:36:56 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *restrict s1, char *restrict s2, size_t n)
{
	unsigned int	length_s1;
	unsigned int	length_s2;
	unsigned int	i;

	length_s1 = 0;
	while(s1[length_s1])
		length_s1++;
	length_s2 = 0;
	while(s2[length_s2])
		length_s2++;
	i = 0;
	while(i < length_s2 && i < n)
	{
		s1[length_s1 + i] = s2[i];
		i++;
	}
	s1[length_s1 + i] = '\0';
	return (s1);
}
