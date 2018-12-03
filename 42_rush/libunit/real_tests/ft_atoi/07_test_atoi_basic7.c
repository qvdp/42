/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_test_atoi_basic7.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:24:05 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/02 14:16:00 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../real_tests.h"

int		test_atoi_basic7(void)
{
	if (atoi("+123456") == ft_atoi("+123456"))
		return (0);
	else
		return (-1);
}