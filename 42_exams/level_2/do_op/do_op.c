#include "do_op.h"

int	main(int argc, char *argv[])
{
	int	result;

	if (argc == 4)
	{
		result = 0;
		if (argv[2][0] == '+')
			result = ft_add(atoi(argv[1]), atoi(argv[3]));	
		if (argv[2][0] == '-')
			result = ft_substract(atoi(argv[1]), atoi(argv[3]));	
		if (argv[2][0] == '*')
			result = ft_multiplicate(atoi(argv[1]), atoi(argv[3]));	
		if (argv[2][0] == '/')
			result = ft_divide(atoi(argv[1]), atoi(argv[3]));
		if (argv[2][0] == '%')
			result = ft_modulo(atoi(argv[1]), atoi(argv[3]));
		printf("%d", result);
	}
	printf("\n");
	return (0);
}
