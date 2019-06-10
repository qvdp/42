#include <unistd.h>

int	main(void)
{
	char letter;

	letter = 'z';
	write(1, &letter, 1);
	return (0);
}
