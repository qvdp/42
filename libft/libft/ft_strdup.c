/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:38:55 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/07 19:44:36 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strdup(char *s1)
{
	int i;
	int length;
	char *cpy

	length = 0;
	while (s1[i])
		length++;
	if (!(cpy = (char*)malloc(sizeof(cpy) * length)))
		return ;
	i = 0;
	while (s1[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
}
