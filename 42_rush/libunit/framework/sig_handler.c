/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:47:38 by qvan-der          #+#    #+#             */
/*   Updated: 2018/12/02 13:51:16 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <sys/wait.h>

char	*ft_sig_handler_part3(pid_t pid)
{
	if (WTERMSIG(pid) == 22)
		return ("\033[1;34m[SIGTTOU]\033[0m");
	if (WTERMSIG(pid) == 23)
		return ("\033[1;34m[SIGIO]\033[0m");
	if (WTERMSIG(pid) == 24)
		return ("\033[1;34m[SIGXCPU]\033[0m");
	if (WTERMSIG(pid) == 25)
		return ("\033[1;34m[SIGXFSZ]\033[0m");
	if (WTERMSIG(pid) == 26)
		return ("\033[1;34m[SIGVTALRM]\033[0m");
	if (WTERMSIG(pid) == 27)
		return ("\033[1;34m[SIGPROF]\033[0m");
	if (WTERMSIG(pid) == 28)
		return ("\033[1;34m[SIGWINCH]\033[0m");
	if (WTERMSIG(pid) == 29)
		return ("\033[1;34m[SIGINFO]\033[0m");
	return ("\033[0;31m[KO]\033[0m");
}

char	*ft_sig_handler_part2(pid_t pid)
{
	if (WTERMSIG(pid) == 11)
		return ("\033[1;34m[SEGV]\033[0m");
	if (WTERMSIG(pid) == 12)
		return ("\033[1;34m[SIGSYS]\033[0m");
	if (WTERMSIG(pid) == 13)
		return ("\033[1;34m[SIGPIPE]\033[0m");
	if (WTERMSIG(pid) == 14)
		return ("\033[1;34m[SIGALRM]\033[0m");
	if (WTERMSIG(pid) == 15)
		return ("\033[1;34m[SIGTERM]\033[0m");
	if (WTERMSIG(pid) == 16)
		return ("\033[1;34m[SIGURG]\033[0m");
	if (WTERMSIG(pid) == 17)
		return ("\033[1;34m[SIGSTOP]\033[0m");
	if (WTERMSIG(pid) == 18)
		return ("\033[1;34m[SIGTSTP]\033[0m");
	if (WTERMSIG(pid) == 19)
		return ("\033[1;34m[SIGCONT]\033[0m");
	if (WTERMSIG(pid) == 20)
		return ("\033[1;34m[SIGCHLD]\033[0m");
	if (WTERMSIG(pid) == 21)
		return ("\033[1;34m[SIGTTIN]\033[0m");
	return (ft_sig_handler_part3(pid));
}

char	*ft_sig_handler(pid_t pid)
{
	if (WIFSIGNALED(pid) == 1)
	{
		if (WTERMSIG(pid) == 1)
			return ("\033[1;34m[SIGHUP]\033[0m");
		if (WTERMSIG(pid) == 2)
			return ("\033[1;34m[SIGINT]\033[0m");
		if (WTERMSIG(pid) == 3)
			return ("\033[1;34m[SIGQUIT]\033[0m");
		if (WTERMSIG(pid) == 4)
			return ("\033[1;34m[SIGILL]\033[0m");
		if (WTERMSIG(pid) == 5)
			return ("\033[1;34m[SIGTRAP]\033[0m");
		if (WTERMSIG(pid) == 6)
			return ("\033[1;34m[SIGABRT]\033[0m");
		if (WTERMSIG(pid) == 7)
			return ("\033[1;34m[SIGEMT]\033[0m");
		if (WTERMSIG(pid) == 8)
			return ("\033[1;34m[SIGFPE]\033[0m");
		if (WTERMSIG(pid) == 9)
			return ("\033[1;34m[SIGKILL]\033[0m");
		if (WTERMSIG(pid) == 10)
			return ("\033[1;34m[BUSE]\033[0m");
	}
	return (ft_sig_handler_part2(pid));
}
