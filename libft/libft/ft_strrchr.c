#include "ft_header.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
		s++;
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s--;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
