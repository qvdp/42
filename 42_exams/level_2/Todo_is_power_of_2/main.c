#include <stdio.h>
#include <stdlib.h>

int is_power_of_2(unsigned int n);
int test(unsigned int n);

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{	
//		printf("%d", is_power_of_2(atoi(argv[1])));
		printf("\n%d\n----\n", test(atoi(argv[1])));
	}
	return (0);
}
