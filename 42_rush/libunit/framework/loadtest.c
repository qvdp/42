#include "inc/libunit.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int   ft_load_test(t_libtest **alist, char *name, int (*f)(void))
{
  t_libtest *list;

  if (!(list = (t_libtest*)malloc(sizeof(t_libtest))))
    return (-1);
  list->result = NULL;
  list->name = strdup(name);
  list->f = f;
  list->next = *alist;
  *alist = list;
  return (0);
}

int  print_result(t_libtest *lst)
{
  int   count;
  int   count_err;

  count = 0;
  count_err = 0;
  while (lst)
  {
    ft_pstr_fd("   > ", 1);
    ft_pstr_fd((lst->name), 1);
    ft_pstr_fd(" : ", 1);
    ft_pstrend_fd((lst->result), 1);
    if (lst->result[8] != 'K')
      count_err++;
    count++;
    lst = lst->next;
  }
  ft_pnbr_fd(count_err, 1);
  ft_pstr_fd("/", 1);
  ft_pnbr_fd(count, 1);
  ft_pstrend_fd(" test checked", 1);
  return (count - count_err);
}

int   ft_launch_tests(t_libtest **lst)
{
  t_libtest *temp_list;

  temp_list = *lst;
  while (temp_list)
  {
    temp_list->result = ft_test(temp_list->f);
    temp_list = temp_list->next;
  }
  return ((print_result(*lst)) == 0 ? 0 : -1);
}

/*void kill_timeout(int sig)
{
    kill(0, SIGUSR1);
}*/

char   *ft_test(int (*f)(void))
{
  pid_t   pid;

  pid = fork();
  //signal(SIGALRM, &kill_timeout);
  if (pid > 0)
  {
    //alarm(5);
    wait(&pid);
  }
  else if (pid == 0)
    exit(f());
  if (pid != 0)
    return (ft_sig_handler(pid));
  else
    return (strdup("\033[0;32m[OK]\033[0m"));
}
