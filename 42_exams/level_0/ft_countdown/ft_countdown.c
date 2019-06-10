#include <unistd.h>

void	ft_putchar (char c)
{
write (1, &c, 1);
}

void	ft_countdown (void)
{
	int i;

	i = 10;
	while (--i >= 0)
		ft_putchar(i + '0');
	ft_putchar ('\n');
}

int	main (int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_countdown();
	return (0);
}
