#include <unistd.h>

int	main (void)
{
	char letter;

	letter = 'a';
	write(1, &letter, 1);
	return (0);
}
