/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_test_atoi_letters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:24:05 by fguarrac          #+#    #+#             */
/*   Updated: 2018/12/02 14:17:47 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../real_tests.h"

int		test_atoi_letters(void)
{
	if (atoi("abs") == ft_atoi("abs"))
		return (0);
	else
		return (-1);
}
