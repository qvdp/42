/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:03:31 by qvan-der          #+#    #+#             */
/*   Updated: 2019/10/08 23:03:32 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fdf(t_env *fdf)
{
	fdf->mlx_id = mlx_init();
	fdf->win_id = mlx_new_window(
		fdf->mlx_id,
		fdf->cam->vw,
		fdf->cam->vh,
		"fdf");
	ft_create_image(fdf);
	mlx_hook(fdf->win_id, 2, 0, &ft_key_move, fdf);
	mlx_loop(fdf->mlx_id);
	return (0);
}
