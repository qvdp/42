/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_test_atoi_null.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:24:05 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/02 18:15:12 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../real_tests.h"

int		test_atoi_null(void)
{
	if (atoi(NULL) == ft_atoi(NULL))
		return (0);
	else
		return (-1);
}
