/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:58:43 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/02 13:58:54 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRUE_TESTS_H
# define TRUE_TESTS_H

# include "./../framework/inc/libunit.h"

int ft_true_tests_launcher(void);
int true_test_ok(void);
int	true_test_bus(void);
int	true_test_ko(void);
int	true_test_segv(void);

#endif
