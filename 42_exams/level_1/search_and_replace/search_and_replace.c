#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}
	
int	main(int argc, char *argv[])
{
	if (argc == 4 && ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
	{
		while (*argv[1])
		{
			ft_putchar(*argv[1] == *argv[2] ? *argv[3] : *argv[1]);
			argv[1]++;
		}
	}
	ft_putchar('\n');
	return (0);
}
