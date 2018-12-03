/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:58:43 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/02 18:15:36 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_TESTS_H
# define REAL_TESTS_H
# include "./../framework/inc/libunit.h"
# include "./../libft/includes/libft.h"

int		ft_atoi_tests_launcher(void);
int		ft_strcat_tests_launcher(void);
int		ft_memcpy_tests_launcher(void);

int		test_atoi_basic(void);
int		test_atoi_basic2(void);
int		test_atoi_basic3(void);
int		test_atoi_basic4(void);
int		test_atoi_basic5(void);
int		test_atoi_basic6(void);
int		test_atoi_basic7(void);
int		test_atoi_negativ(void);
int		test_atoi_letter(void);
int		test_atoi_letters(void);
int		test_atoi_null(void);

int		test_strcat_basic1(void);
int		test_strcat_basic2(void);
int		test_strcat_basic3(void);
int		test_strcat_basic4(void);
int		test_strcat_basic5(void);
int		test_strcat_basic6(void);

int		test_memcpy_basic1(void);
int		test_memcpy_basic2(void);

#endif
