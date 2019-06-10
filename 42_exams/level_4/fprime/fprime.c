#include <stdlib.h>
#include <stdio.h>

void	ft_fprime(int nbr)
{
	int	div;

	if (nbr == 1)
		printf("1");
	else
	{
		while (nbr > 1)
		{
			div = 2;
			while( nbr % div != 0)
				div++;
			nbr /= div;
			printf("%d", div);
			if (nbr > 1)
				printf("*");
		}
	}
}

int	main (int argc, char *argv[])
{
	if (argc == 2)
		ft_fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
