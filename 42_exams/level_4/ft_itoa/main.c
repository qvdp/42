#include <unistd.h>

char	*ft_itoa(int nbr);

void	ft_putstr(char *str)
{
	while (str && *str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main (int argc, char *argv[])
{
	(void)argv;
	if (argc == 1)
	{
		ft_putstr(ft_itoa(0));
		ft_putstr(ft_itoa(-1));
		ft_putstr(ft_itoa(1));
		ft_putstr(ft_itoa(1234));
		ft_putstr(ft_itoa(-100000));
		ft_putstr(ft_itoa(-2147483648));
		ft_putstr(ft_itoa(-2147483647));
		ft_putstr(ft_itoa(2147483647));
		ft_putstr(ft_itoa(2147483646));
		ft_putstr(ft_itoa(10000));
		ft_putstr(ft_itoa(10000));
		ft_putstr(ft_itoa(10000));
	}
	return (0);
}
