#include "libft.h"

void	ft_puthex_upper(int n)
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
		ft_puthex_upper(abs / 16);
	else if (abs <= 9)
		ft_putchar(abs + '0');
	else
	{
		abs == 10 ? ft_putchar('A') : 0;
		abs == 11 ? ft_putchar('B') : 0;
		abs == 12 ? ft_putchar('C') : 0;
		abs == 13 ? ft_putchar('D') : 0;
		abs == 14 ? ft_putchar('E') : 0;
		abs == 15 ? ft_putchar('F') : 0;
	}
}
