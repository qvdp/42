/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:48:01 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/02 23:41:01 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libunit.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_load_test(t_libtest **alist, char *name, int (*f)(void))
{
	t_libtest	*list;

	if (!(list = (t_libtest*)malloc(sizeof(t_libtest))))
		return ;
	list->result = NULL;
	list->name = name;
	list->f = f;
	list->next = *alist;
	*alist = list;
}

int		print_result(t_libtest *lst, int fd)
{
	int	count;
	int	count_err;

	count = 0;
	count_err = 0;
	while (lst)
	{
		ft_pstr_fd("   > ", fd);
		ft_pstr_fd((lst->name), fd);
		ft_pstr_fd(" : ", fd);
		ft_pstrend_fd((lst->result), fd);
		if (lst->result[8] == 'k')
			count_err++;
		count++;
		lst = lst->next;
	}
	if (count_err == 0)
		ft_pstrend_fd("All tests passed.", fd);
	else
	{
		ft_pnbr_fd(count_err, fd);
		ft_pstrend_fd(" fail tests.", fd);
	}
	ft_pstrend_fd("", fd);
	return (count_err);
}

int		ft_launch_tests(t_libtest **lst)
{
	t_libtest	*temp_list;
	int			fd;

	temp_list = *lst;
	if (!temp_list)
	{
		ft_pstrend_fd("An error has occured.", 1);
		return (-1);
	}
	while (temp_list)
	{
		temp_list->result = ft_test(temp_list->f);
		temp_list = temp_list->next;
	}
	temp_list = *lst;
	fd = open("result.txt", O_RDWR | O_CREAT, 0666);
	print_result(temp_list, fd);
	close(fd);
	return (print_result(*lst, 1));
}

char	*ft_test(int (*f)(void))
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
		wait(&pid);
	else if (pid == 0)
		exit(f());
	if (pid != 0)
		return (ft_sig_handler(pid));
	else
		return ("\033[0;32m[OK]\033[0m");
}
