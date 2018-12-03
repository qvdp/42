/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_test_memcpy_basic2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:06:09 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/02 18:12:18 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../real_tests.h"
#include <string.h>

int			test_memcpy_basic2(void)
{
	char	*s1;
	char	*s2;

	s1 = "Salut, c'est cool!";
	s2 = NULL;
	ft_memcpy(s2, s1, strlen(s1));
	if (memcmp(s1, s2, strlen(s1)) == 0)
		return (0);
	else
		return (-1);
}
