#include "true_tests.h"

int   main(void)
{
  ft_pstrend_fd("*********************************", 1);
  ft_pstrend_fd("**       42 - Unit Tests       **", 1);
  ft_pstrend_fd("*********************************", 1);
  ft_pstrend_fd("STRLEN:", 1);
  return(ft_true_tests_launcher());
}
