/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_segv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:57:31 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/01 16:50:11 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../true_tests.h"
#include <string.h>

int	true_test_segv(void)
{
	char *ptr;

	ptr = NULL;
	ptr[0] = '4';
	ptr[1] = '2';
	return (0);
}
