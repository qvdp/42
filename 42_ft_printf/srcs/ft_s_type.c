#include "../includes/ft_printf.h"

int	ft_s_type(va_list *args)
{
  char *s;

  s = va_arg(*args, char*);
  ft_putstr(s);
	return (1);
}
