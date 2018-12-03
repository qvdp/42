/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:50:31 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/02 14:44:17 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int	main(void)
{
	int count_err;
	int ret;

	ret = 0;
	count_err = 0;
	ft_pstrend_fd("*********************************", 1);
	ft_pstrend_fd("**       42 - Unit Tests       **", 1);
	ft_pstrend_fd("*********************************", 1);
	ft_pstrend_fd("", 1);
	if (((ret += ft_atoi_tests_launcher()) != 0))
		count_err++;
	if (((ret += ft_strcat_tests_launcher()) != 0))
		count_err++;
	if (((ret += ft_memcpy_tests_launcher()) != 0))
		count_err++;
	if (count_err == 0)
		ft_pstrend_fd("All test succed", 1);
	else
	{
		ft_pstr_fd("You need to handle ", 1);
		ft_pnbr_fd(ret, 1);
		ft_pstr_fd(" more case in ", 1);
		ft_pnbr_fd(count_err, 1);
		ft_pstrend_fd(" function.", 1);

	}
	return (0);
}
