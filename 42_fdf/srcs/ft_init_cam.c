/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:03:38 by qvan-der          #+#    #+#             */
/*   Updated: 2019/10/08 23:14:35 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_cam(t_env *fdf)
{
	t_cam	*cam;

	if (!(cam = (t_cam*)ft_memalloc(sizeof(t_cam))))
		return (0);
	cam->h_trans = 1;
	cam->v_trans = 1;
	cam->scale = 1;
	cam->a_x = 0;
	cam->a_y = 0;
	cam->a_z = 0;
	cam->proj = 0;
	cam->vw = 1366;
	cam->vh = 768;
	fdf->cam = cam;
	return (1);
}
