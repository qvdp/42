#include "inc/libunit.h"
#include <stdlib.h>

char *ft_sig_handler(pid_t pid)
{
  if (WIFSIGNALED(pid) == 1)
  {
    if (WTERMSIG(pid) == 1)
      return (strdup("\033[1;34m[SIGHUP]\033[0m"));
    if (WTERMSIG(pid) == 2)
      return (strdup("\033[1;34m[SIGINT]\033[0m"));
    if (WTERMSIG(pid) == 3)
      return (strdup("\033[1;34m[SIGQUIT]\033[0m"));
    if (WTERMSIG(pid) == 4)
      return (strdup("\033[1;34m[SIGILL]\033[0m"));
    if (WTERMSIG(pid) == 5)
      return (strdup("\033[1;34m[SIGTRAP]\033[0m"));
    if (WTERMSIG(pid) == 6)
      return (strdup("\033[1;34m[SIGABRT]\033[0m"));
    if (WTERMSIG(pid) == 7)
      return (strdup("\033[1;34m[SIGEMT]\033[0m"));
    if (WTERMSIG(pid) == 8)
      return (strdup("\033[1;34m[SIGFPE]\033[0m"));
    if (WTERMSIG(pid) == 9)
      return (strdup("\033[1;34m[SIGKILL]\033[0m"));
    if (WTERMSIG(pid) == 10)
      return (strdup("\033[1;34m[SIGBUS]\033[0m"));
  }
  return (ft_sig_handler_part2(pid));
}

char *ft_sig_handler_part2(pid_t pid)
{
  if (WTERMSIG(pid) == 11)
    return (strdup("\033[1;34m[SIGSEGV]\033[0m"));
  if (WTERMSIG(pid) == 12)
    return (strdup("\033[1;34m[SIGSYS]\033[0m"));
  if (WTERMSIG(pid) == 13)
    return (strdup("\033[1;34m[SIGPIPE]\033[0m"));
  if (WTERMSIG(pid) == 14)
    return (strdup("\033[1;34m[SIGALRM]\033[0m"));
  if (WTERMSIG(pid) == 15)
    return (strdup("\033[1;34m[SIGTERM]\033[0m"));
  if (WTERMSIG(pid) == 16)
    return (strdup("\033[1;34m[SIGURG]\033[0m"));
  if (WTERMSIG(pid) == 17)
    return (strdup("\033[1;34m[SIGSTOP]\033[0m"));
  if (WTERMSIG(pid) == 18)
    return (strdup("\033[1;34m[SIGTSTP]\033[0m"));
  if (WTERMSIG(pid) == 19)
    return (strdup("\033[1;34m[SIGCONT]\033[0m"));
  if (WTERMSIG(pid) == 20)
    return (strdup("\033[1;34m[SIGCHLD]\033[0m"));
  if (WTERMSIG(pid) == 21)
    return (strdup("\033[1;34m[SIGTTIN]\033[0m"));
  return (ft_sig_handler_part3(pid));
}

char *ft_sig_handler_part3(pid_t pid)
{
  if (WTERMSIG(pid) == 22)
    return (strdup("\033[1;34m[SIGTTOU]\033[0m"));
  if (WTERMSIG(pid) == 23)
    return (strdup("\033[1;34m[SIGIO]\033[0m"));
  if (WTERMSIG(pid) == 24)
    return (strdup("\033[1;34m[SIGXCPU]\033[0m"));
  if (WTERMSIG(pid) == 25)
    return (strdup("\033[1;34m[SIGXFSZ]\033[0m"));
  if (WTERMSIG(pid) == 26)
    return (strdup("\033[1;34m[SIGVTALRM]\033[0m"));
  if (WTERMSIG(pid) == 27)
    return (strdup("\033[1;34m[SIGPROF]\033[0m"));
  if (WTERMSIG(pid) == 28)
    return (strdup("\033[1;34m[SIGWINCH]\033[0m"));
  if (WTERMSIG(pid) == 29)
    return (strdup("\033[1;34m[SIGINFO]\033[0m"));
  return (strdup("\033[0;31m[KO]\033[0m"));
}
