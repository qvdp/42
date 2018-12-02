#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <stdlib.h>

typedef struct		s_libtest
{
	char			*name;
  int       (*f)(void);
  char       *result;
	struct s_libtest	*next;
}					t_libtest;

char *ft_sig_handler(int WSTOPSIG);
char *ft_sig_handler_part2(int WSTOPSIG);
char *ft_sig_handler_part3(int WSTOPSIG);
int   ft_load_test(t_libtest **alist, char *name, int (*f)(void));
int   ft_launch_tests(t_libtest **lst);
char   *ft_test(int (*f)(void));
size_t		ft_strlength(const char *str);
void	ft_pstrend_fd(char const *s, int fd);
void	ft_pchar_fd(char c, int fd);
void	ft_pstr_fd(char *str, int fd);
void	ft_pnbr_fd(int n, int fd);
char		*strdup(const char *s1);
int  print_result(t_libtest *lst);

#endif
