/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:49:53 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/12 20:36:30 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long				ft_atoi(const char *str)
{
	unsigned long	i;
	unsigned long	temp;
	int				is_negative;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ')
		i++;
	is_negative = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = 1;
		i++;
	}
	temp = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = temp * 10 + (str[i] - '0');
		i++;
	}
	if (temp > 9223372036854775807ULL)
		return (is_negative ? 0 : -1);
	return (is_negative ? temp * -1 : temp);
}
