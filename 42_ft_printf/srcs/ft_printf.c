#include "../includes/ft_printf.h"
#include <stdio.h>
int	ft_printf(const char  *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		// If `%` is detected, verify what happens next with parser
		if (*format == '%')
		{
			ft_type_parser(&format, &ap);
		}
		else
			write(1,format,1);
		format++;
	}
	va_end(ap);
	return (0);
}
