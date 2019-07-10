#include <stdlib.h>
#include <stdio.h>
int     *ft_rrange(int start, int end);

int	main(int argc, char *argv[])
{
	int	*array;

	if(argc == 3)
	{
		array = ft_rrange(atoi(argv[1]),atoi(argv[2]));
		while (*array)
		{
			printf("%d\n", *array);
			array++;
		}
	}			
	return (0);
}
