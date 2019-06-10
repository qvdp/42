#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1 ,&c, 1);
}

void	ft_print_letters(char letter, int len)
{
	while(len-- > 0)
		ft_putchar(letter);
}

int	ft_get_letter_pos(char letter)
{
	int	pos;
	
	if (letter >= 'A' && letter <= 'Z')
		pos = letter + 32 - 96;
	else if (letter >= 'a' && letter <= 'z')
		pos = letter - 96;
	else
		pos = 1;
	return (pos);	
}

int	main(int argc, char *argv[])
{
	int	i;
	int pos;

	i = 0;	
	if (argc == 2)
	{
		while (argv[1][i])
		{
			pos = ft_get_letter_pos(argv[1][i]);
			ft_print_letters(argv[1][i], pos);
			i++;	
		}
	}
	ft_putchar('\n');
	return (0);
}
