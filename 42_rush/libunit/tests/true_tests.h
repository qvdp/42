#ifndef TRUE_TESTS_H
# define TRUE_TESTS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include "./../framework/inc/libunit.h"

int ft_true_tests_launcher(void);
int true_test_ok(void);
int	true_test_bus(void);
int	true_test_ko(void);
int	true_test_segv(void);

#endif
