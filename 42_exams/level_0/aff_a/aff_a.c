#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int i;

	if (argc != 2)
		ft_putchar('a');
	else
	{
		i = 0;
		while (argv[1][i] && argv[1][i] != 'a')
			i++;
		if (argv[1][i] == 'a')
			ft_putchar('a');
	}
	ft_putchar('\n');
	return (0);
}
