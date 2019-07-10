#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int	*array;
	int	size;
	
	size = (end - start) >= 0 ? (end - start) + 1 : -1 * (end - start) + 1;
	printf("Size: %d\n", size);
	if((array = (int*)malloc(sizeof(int) * size)))
	{
		while (size > 0)
		{
			printf("array[%d] =",size);
			printf(" %d",start);
			array[size--] = start >= end ? start-- : start++;
			printf(" | %d\n",array[size + 1]);
		}
	}
	else
	{
		array = NULL;
	}
	return(array);
}
