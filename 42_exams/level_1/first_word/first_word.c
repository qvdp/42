#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int i;
	if (argc == 2)
	{
		while (argv[1][i] && ft_isspace(argv[1][i]))
			i++;
		while (argv[1][i] && !ft_isspace(argv[1][i]))
		{
			ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');	
	return (0);
}
