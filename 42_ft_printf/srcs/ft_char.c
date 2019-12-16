#include "../includes/ft_printf.h"
#include <stdio.h>
// #include "ft_printf.h"
// #include "libft.h"
// #include <ctype.h>
//
// t_tab			*display_c(t_tab *tab)
// {
// 	wint_t		c;
//
// 	if (ft_strcmp(tab->argument_flag, "l") == 0)
// 		c = (unsigned long)va_arg(tab->args, unsigned long);
// 	else if (tab->specifier_flag == 'C')
// 		c = (wchar_t)va_arg(tab->args, wint_t);
// 	else
// 		c = (char)va_arg(tab->args, int);
// 	c = (wint_t)c;
// 	if (tab->convert[3] == '0' && tab->convert[0] != '-')
// 		display_gap(tab, '0', tab->field_width - 1, 1);
// 	else if (tab->convert[0] != '-')
// 		display_gap(tab, ' ', tab->field_width - 1, 1);
// 	display_wchar(c, tab);
// 	if (tab->convert[0] == '-')
// 		display_gap(tab, ' ', tab->field_width - 1, 1);
// 	return (tab);
// }

int	ft_c_type(va_list *args)
{
  int c;

  ft_putstr("Handle %c\n");
  c = va_arg(*args, int);
  ft_putchar(c);
	return (1);
}
