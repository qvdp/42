#include "libft.h"

void	ft_puthex_lower(int n)
{
	unsigned int abs;

	if (n < 0)
	{
		ft_putchar('-');
		abs = n * -1;
	}
	else
		abs = n;
	if (abs >= 16)
		ft_puthex_lower(abs / 16);
	else if (abs <= 9)
		ft_putchar(abs + '0');
	else
	{
		abs == 10 ? ft_putchar('a') : 0;
		abs == 11 ? ft_putchar('b') : 0;
		abs == 12 ? ft_putchar('c') : 0;
		abs == 13 ? ft_putchar('d') : 0;
		abs == 14 ? ft_putchar('e') : 0;
		abs == 15 ? ft_putchar('f') : 0;
	}
}
