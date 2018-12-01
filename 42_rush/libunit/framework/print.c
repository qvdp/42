#include <stdlib.h>
#include <unistd.h>
#include "inc/libunit.h"

size_t		ft_strlength(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_pchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_pstrend_fd(char const *s, int fd)
{
    if (s)
  	   write(1, s, ft_strlength(s));
		ft_pchar_fd('\n', fd);
}

void	ft_pstr_fd(char *str, int fd)
{
	if (str)
	   write(fd, str, ft_strlength(str));
}

void	ft_pnbr_fd(int n, int fd)
{
	unsigned int abs;

	if (n < 0)
	{
		ft_pchar_fd('-', fd);
		abs = n * -1;
	}
	else
		abs = n;
	if (abs > 9)
		ft_pnbr_fd(abs / 10, fd);
	ft_pchar_fd(abs % 10 + '0', fd);
}

char		*strdup(const char *s1)
{
	int		i;
	size_t	length;
	char	*cpy;

	length = ft_strlength(s1);
	if (!(cpy = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
