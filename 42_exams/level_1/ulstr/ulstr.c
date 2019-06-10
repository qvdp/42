#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_inverseCase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	main(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			ft_putchar(ft_inverseCase(argv[1][i]));
			i++;
		}
	}	
	ft_putchar('\n');
	return (0);
}
