#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int len;
	
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	int len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		while (--len >= 0)
		{
			ft_putchar(argv[1][len]);
		}
	}	
	ft_putchar('\n');
	return (0);
}
