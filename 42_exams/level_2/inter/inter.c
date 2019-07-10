#include <unistd.h>

int	ft_checkLetter(int pos, char *str1, char *str2)
{
	int	i;
	
	i = 0;
	while (i < pos)
	{
		if (str1[pos] == str1[i])
			return (0); 
		i++;
	}
	while (*str2)
	{
		if (*str2 == str1[pos])
			return (1);
		str2++;
	}
	return(0);
}

int	main(int argc, char *argv[])
{
	int	i;
	
	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (ft_checkLetter(i, argv[1], argv[2]))
			{
				write(1,&argv[1][i],1);;	
			}
			i++;
		}
	}
	write(1,"\n",1);
	return (0);
}
