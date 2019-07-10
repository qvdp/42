#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_rot(char c)
{
	char	letter;

	if (c >= 65 && c <= 77)
		letter = c + 25 - ((c - 'A') * 2);
	else if (c >= 97 && c <= 109)
		letter = c + 25 - ((c - 'a') * 2);
	else if (c >= 78 && c <= 90)
		letter = c - 25 + (('Z' - c) * 2);
	else if (c >= 110 && c <= 122)
		letter = c - 25 + (('z' - c) * 2);
	else
		letter = c;
	return (letter);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			ft_putchar(ft_rot(*argv[1]));
			argv[1]++;
		}	
	}
	ft_putchar('\n');
	return (0);
}
