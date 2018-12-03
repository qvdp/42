/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_atoi_tests_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:50:12 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/02 18:07:50 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../real_tests.h"
#include <stdlib.h>

int		ft_atoi_tests_launcher(void)
{
	t_libtest	*testlist;
	int			ret;

	ft_pstrend_fd("FT_ATOI :", 1);
	testlist = NULL;
	ft_load_test(&testlist, "Basic test", &test_atoi_basic);
	ft_load_test(&testlist, "Basic test with space", &test_atoi_basic2);
	ft_load_test(&testlist, "Basic test with spaces", &test_atoi_basic3);
	ft_load_test(&testlist, "Basic test with ending spaces", &test_atoi_basic4);
	ft_load_test(&testlist, "Basic test surrunded by spaces",
				&test_atoi_basic5);
	ft_load_test(&testlist, "Basic test with sapce in between",
				&test_atoi_basic6);
	ft_load_test(&testlist, "Basic test with + sign", &test_atoi_basic7);
	ft_load_test(&testlist, "Basic test with - sign", &test_atoi_negativ);
	ft_load_test(&testlist, "Basic test with a letter at beggining",
				&test_atoi_letter);
	ft_load_test(&testlist, "Basic test with only letters", &test_atoi_letters);
	ft_load_test(&testlist, "Segmentation fault test", &test_atoi_null);
	if ((ret = ft_launch_tests(&testlist)) != 0)
		return (ret);
	return (0);
}
