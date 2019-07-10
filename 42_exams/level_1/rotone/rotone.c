#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (*argv[1] >= 'A' && *argv[1] < 'Z')
				ft_putchar(*argv[1] + 1);
			else if (*argv[1] == 'Z')
				ft_putchar('A');
			else if (*argv[1] >= 'a' && *argv[1] < 'z')
				ft_putchar(*argv[1] + 1);
			else if (*argv[1] == 'Z')
				ft_putchar('a');
			else
				ft_putchar(*argv[1]);
			argv[1]++;
		}
	}
	ft_putchar('\n');
	return (0);
}
