#include "ft_header.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *b_copy;
	size_t i;

	b_copy = b;
	i = 0;
	while (i < len)
	{
	  b_copy[i] = (unsigned char)c;
		i++;
	}
	return ((unsigned char*)b);
}
