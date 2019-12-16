#include "libft.h"

void	ft_putoct(int n)
{
	unsigned int abs;

	if (n < 0)
	{
		ft_putchar('-');
		abs = n * -1;
	}
	else
		abs = n;
	if (n >= 8)
		ft_putoct(n / 8);
	ft_putchar(n % 8 + '0');
}
