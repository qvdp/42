/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_strcat_basic1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:51:15 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/02 18:14:21 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../real_tests.h"

int		test_strcat_basic1(void)
{
	char src[20] = "Salut, ";
	char *dst;
	char src2[20] = "Salut, ";
	char *dst2;

	dst = "coucou!";
	dst2 = "coucou!";
	if ((strcmp(ft_strcat(src, dst), strcat(src2, dst2))) == 0)
		return (0);
	else
		return (-1);
}
