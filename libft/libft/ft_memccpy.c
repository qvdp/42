#include "ft_header.h"

void 		*ft_memccpy(void *restrict dst, const void *restrict src, int c, qsize_t n)
{
	unsigned char *dst_copy;
	const unsigned char *src_copy;
	size_t i;

	dst_copy = dst;
	src_copy = src;
	i = 0;
	while (i < n)
	{
	  dst_copy[i] = src_copy[i];
		i++;
	}
	return ((unsigned char*)dst);
}
