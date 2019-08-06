#include "../includes/ft_printf.h"
#include <stdio.h>
int	ft_d_type(va_list *args)
{
	int d;

	d = va_arg(*args, int);
	ft_putnbr(d);
	return (1);
}

int	ft_u_type(va_list *args)
{
	unsigned int d;

	d = va_arg(*args, unsigned int);
	ft_putunbr(d);
	return (1);
}
