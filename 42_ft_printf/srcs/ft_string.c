#include "../includes/ft_printf.h"
#include <stdio.h>
int	ft_s_type(va_list *args)
{
  char *s;

  ft_putstr("Handle %s\n");
  s = va_arg(*args, char*);
  ft_putstr(s);
	return (1);
}

// #include "ft_printf.h"
// #include "libft.h"
//
// t_tab			*display_s(t_tab *tab)
// {
// 	char		*s;
// 	int			i;
// 	int			len;
//
// 	i = 0;
// 	s = va_arg(tab->args, char *);
// 	if (tab->precision > -1 && s)
// 		s = ft_strndup(s, tab->precision);
// 	else if (tab->precision == -1 && s)
// 		s = ft_strdup(s);
// 	else if (tab->precision > -1 && !s)
// 		s = ft_strndup("(null)", tab->precision);
// 	else if (tab->precision == -1 && !s)
// 		s = ft_strdup("(null)");
// 	len = ft_strlen(s);
// 	tab->len += len;
// 	if (tab->convert[3] == '0' && tab->convert[0] != '-')
// 		display_gap(tab, '0', tab->field_width - len, 1);
// 	else if (tab->convert[0] != '-')
// 		display_gap(tab, ' ', tab->field_width - len, 1);
// 	ft_putstr(s);
// 	if (tab->convert[0] == '-')
// 		display_gap(tab, ' ', tab->field_width - len, 1);
// 	free(s);
// 	return (tab);
// }
