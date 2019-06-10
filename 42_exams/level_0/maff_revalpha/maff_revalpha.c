#include <unistd.h>

void	ft_putchar (char c)
{
	write(1, &c, 1);
}

int	main (void)
{
	char letter;
	char temp;

	letter = 'z';
	while (letter >= 'a')
	{
		temp = (letter % 2 == 0) ? letter : letter - 32;
		ft_putchar(temp);
		letter--;
	}
	ft_putchar('\n');
	return (0);
}
