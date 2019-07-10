int	ft_atoi(const char *str)
{
	int nbr;
	int sign;

	nbr = 0;
	sign = 1;
	while (*str == '\f' || *str == '\r' || *str == '\t' ||	*str == '\n' ||	*str == '\v' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = *str == '-' ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}
