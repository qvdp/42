/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_listener.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:03:23 by qvan-der          #+#    #+#             */
/*   Updated: 2019/10/15 22:19:57 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_move(int keycode, t_env *fdf)
{
	if (keycode == 123 || keycode == 124)
		fdf->cam->h_trans += keycode == 124 ? 10 : -10;
	if (keycode == 125 || keycode == 126)
		fdf->cam->v_trans += keycode == 125 ? 10 : -10;
	if (keycode == 1)
		fdf->cam->scale -= fdf->cam->scale > 1 ? 1 : 0;
	if (keycode == 13)
		fdf->cam->scale += 1;
	if (keycode == 12 && fdf->cam->proj == 0)
		fdf->cam->a_x -= 0.10;
	if (keycode == 14 && fdf->cam->proj == 0)
		fdf->cam->a_x += 0.10;
	if (keycode == 0 && fdf->cam->proj == 0)
		fdf->cam->a_y -= 0.10;
	if (keycode == 2 && fdf->cam->proj == 0)
		fdf->cam->a_y += 0.10;
	if (keycode == 6 && fdf->cam->proj == 0)
		fdf->cam->a_z -= 0.10;
	if (keycode == 8 && fdf->cam->proj == 0)
		fdf->cam->a_z += 0.10;
	if (keycode == 7)
		fdf->cam->proj += fdf->cam->proj != 2 ? 1 : -2;
	if (keycode == 53)
		exit(0);
	return (ft_create_image(fdf));
}
