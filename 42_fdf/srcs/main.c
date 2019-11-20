/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:03:43 by qvan-der          #+#    #+#             */
/*   Updated: 2019/10/16 22:56:45 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_freearr(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	fdf;

	if (ft_check(argc, argv) == -1)
		return (-1);
	ft_bzero(&fdf, sizeof(t_env));
	ft_build_map(argv[1], &fdf);
	ft_init_cam(&fdf);
	ft_fdf(&fdf);
	free(&fdf.map->coors);
	ft_bzero(&fdf, sizeof(t_env));
	return (0);
}
