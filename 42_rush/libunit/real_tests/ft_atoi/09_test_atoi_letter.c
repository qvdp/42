/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_test_atoi_letter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:24:05 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/02 14:18:22 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./../real_tests.h"

int		test_atoi_letter(void)
{
	if (atoi("  a123456") == ft_atoi("  a123456"))
		return (0);
	else
		return (-1);
}