#include "ft_header.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	size_t j;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && j < len)
				j++;
			if (!needle[j] || j == len)
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
