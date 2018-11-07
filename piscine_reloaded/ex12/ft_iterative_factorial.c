/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:50:31 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/05 21:03:49 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;

	if (nb > 12 || nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
	{
		res = 1;
		while (nb > 1)
		{
			res *= nb;
			nb--;
		}
		return (res);
	}
}
