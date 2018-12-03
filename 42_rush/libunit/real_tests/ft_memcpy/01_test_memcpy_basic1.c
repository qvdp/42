/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_memcpy_basic1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:44:00 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/02 16:50:11 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../real_tests.h"
#include <string.h>

int		test_memcpy_basic1(void)
{
	char *s1;
	char s2[19];

	s1 = "Salut, c'est cool!";
	ft_memcpy(s2, s1, strlen(s1));
	if (memcmp(s1, s2, strlen(s1)) == 0)
		return (0);
	else
		return (-1);
}
