#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	char	*string;
	int	sign;
	int	temp_nbr;
	int	size;

	printf("\ntrying to convert %d\n", nbr);
	sign = (nbr < 0) ? -1 : 1;
	size = (sign < 0) ? 2 : 1;
	temp_nbr = nbr;
	while (temp_nbr /= 10)
		size++;
	if (!(string = (char*)malloc(sizeof(char)*(size + 1))))
		return (NULL);
	string[size] = '\0';
	while (size >= 0)
	{
		string[--size] = ((nbr  % 10) * sign) + 48;
		nbr /= 10;
	}
	string[0] = (sign == -1) ? '-' : string[0];
	return (string);
}
