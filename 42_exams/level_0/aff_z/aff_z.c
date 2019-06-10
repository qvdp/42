#include <unistd.h>

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

int	main (int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_putchar('z');
	ft_putchar('\n');
}
