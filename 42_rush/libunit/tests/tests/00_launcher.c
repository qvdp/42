#include "../true_tests.h"

int ft_true_tests_launcher(void)
{
  t_libtest *testlist;

  testlist = NULL;
  ft_load_test(&testlist, "Segmentation Fault true_test", &true_test_segv);
  ft_load_test(&testlist, "Bus Error true_test", &true_test_bus);
  ft_load_test(&testlist, "KO true_test", &true_test_ko);
  ft_load_test(&testlist, "OK true_test", &true_test_ok);
  return(ft_launch_tests(&testlist));
}
