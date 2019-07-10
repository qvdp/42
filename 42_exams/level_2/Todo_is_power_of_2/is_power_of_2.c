int	is_power_of_2(unsigned int n)
{
	int i;

	i = 0;
	if (n >= 0)
	{
		i++;
		while(i < n && i != n)
		{
			i *= 2;	
		}	
	}
	return (i == n ? 1 : 0);
}

int		test(unsigned int n)
{
	return ((n & (-n)) == n ? 1 : 0);
}
