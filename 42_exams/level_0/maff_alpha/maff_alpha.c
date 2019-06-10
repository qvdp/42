#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main()
{

	char letter;

	letter = 'a';
	while (letter <= 'z')
	{
		ft_putchar(letter % 2 != 0 ? letter : letter - 32);
		letter++;	
	}
	ft_putchar('\n');
	return (0);
}
