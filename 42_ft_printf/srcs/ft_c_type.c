#include "../includes/ft_printf.h"

int	ft_c_type(va_list *args)
{
  int c;

  c = va_arg(*args, int);
  ft_putchar(c);
	return (1);
}
