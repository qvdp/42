/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:02:29 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/02 14:05:30 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

typedef struct			s_libtest
{
	char				*name;
	int					(*f)(void);
	char				*result;
	struct s_libtest	*next;
}						t_libtest;

char					*ft_sig_handler(int sig);
void					ft_load_test(t_libtest **alist,
						char *name, int (*f)(void));
int						ft_launch_tests(t_libtest **lst);
char					*ft_test(int (*f)(void));
int						ft_strlength(const char *str);
void					ft_pstrend_fd(char const *s, int fd);
void					ft_pchar_fd(char c, int fd);
void					ft_pstr_fd(char *str, int fd);
void					ft_pnbr_fd(int n, int fd);
char					*strdup(const char *s1);
int						print_result(t_libtest *lst, int fd);

#endif
