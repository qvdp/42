/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_atoi_tests_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:50:12 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/02 18:13:08 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../real_tests.h"
#include <stdlib.h>

int		ft_strcat_tests_launcher(void)
{
	t_libtest	*testlist;
	int			ret;

	ft_pstrend_fd("FT_STRCAT :", 1);
	testlist = NULL;
	ft_load_test(&testlist, "Basic test", &test_strcat_basic1);
	ft_load_test(&testlist, "Basic test with dst empty", &test_strcat_basic2);
	ft_load_test(&testlist, "Basic test with src empty", &test_strcat_basic3);
	ft_load_test(&testlist, "Basic test with dst & src empty",
				&test_strcat_basic5);
	ft_load_test(&testlist, "SIGABORT test", &test_strcat_basic4);
	ft_load_test(&testlist, "Segmentation fault test", &test_strcat_basic6);
	if ((ret = ft_launch_tests(&testlist)) != 0)
		return (ret);
	return (0);
}
