/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_strcat_basic6.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:51:15 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/02 18:13:59 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../real_tests.h"
#include <stdlib.h>

int			test_strcat_basic6(void)
{
	char	src[20] = "Salut, ";
	char	*dst;
	char	src2[20] = "Salut, ";
	char	*dst2;

	dst = NULL;
	dst2 = NULL;
	if ((strcmp(ft_strcat(src, dst), strcat(src2, dst2))) == 0)
		return (0);
	else
		return (-1);
}
