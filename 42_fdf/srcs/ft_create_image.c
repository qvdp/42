/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:02:35 by qvan-der          #+#    #+#             */
/*   Updated: 2019/10/16 23:11:39 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_handle_view(t_env *fdf, t_coor *tmp, int *a, int *b)
{
	*a = tmp->x;
	*b = tmp->y;
	if (fdf->cam->proj == 1 || fdf->cam->proj == 2)
	{
		tmp->x = (*a - *b) * cos(fdf->cam->proj == 1 ? 0.5 : 0);
		tmp->y = -tmp->z + (*a + *b) * sin(fdf->cam->proj == 1 ? 0.5 : 0);
	}
}

void		ft_handle_projection(t_env *fdf, t_coor *tmp, int *a, int *b)
{
	if (fdf->cam->a_x != 0 && fdf->cam->proj == 0)
	{
		*b = tmp->y;
		tmp->y = cos(fdf->cam->a_x) * *b + sin(fdf->cam->a_x) * tmp->z;
		tmp->z = cos(fdf->cam->a_x) * tmp->z - sin(fdf->cam->a_x) * *b;
	}
	if (fdf->cam->a_y != 0 && fdf->cam->proj == 0)
	{
		*a = tmp->x;
		tmp->x = cos(fdf->cam->a_y) * *a + sin(fdf->cam->a_y) * tmp->z;
		tmp->z = cos(fdf->cam->a_y) * tmp->z - sin(fdf->cam->a_y) * *a;
	}
	if (fdf->cam->a_z != 0 && fdf->cam->proj == 0)
	{
		*a = tmp->x;
		*b = tmp->y;
		tmp->x = cos(fdf->cam->a_z) * *a - sin(fdf->cam->a_z) * *b;
		tmp->y = cos(fdf->cam->a_z) * *b + sin(fdf->cam->a_z) * *a;
	}
}

t_coor		*ft_ctrl_update(t_env *fdf)
{
	t_coor	*tmp;
	int		tmp_x;
	int		tmp_y;
	int		i;

	if (!(tmp = (t_coor*)malloc(sizeof(t_coor) * fdf->map->length)))
		return (NULL);
	i = -1;
	while (++i < fdf->map->length)
	{
		tmp[i].x = fdf->map->coors[i]->x * fdf->cam->scale;
		tmp[i].y = fdf->map->coors[i]->y * fdf->cam->scale;
		tmp[i].z = fdf->map->coors[i]->z * fdf->cam->scale;
		tmp_x = 0;
		tmp_y = 0;
		ft_handle_projection(fdf, &tmp[i], &tmp_x, &tmp_y);
		ft_handle_view(fdf, &tmp[i], &tmp_x, &tmp_y);
		tmp[i].x += (fdf->cam->vw / 2) + fdf->cam->h_trans;
		tmp[i].y += (fdf->cam->vh + fdf->map->y_max * fdf->cam->scale) / 2
		+ fdf->cam->v_trans;
	}
	return (tmp);
}

int			ft_create_image(t_env *fdf)
{
	t_coor	*tmp;
	int		i;

	fdf->img_id = mlx_new_image(fdf->mlx_id, fdf->cam->vw, fdf->cam->vh);
	if (!(fdf->image = (t_image*)malloc(sizeof(t_image))))
		return (-1);
	fdf->image->pixels = mlx_get_data_addr(fdf->img_id,
		&fdf->image->bits_per_pixel, &fdf->image->line_size,
		&fdf->image->endian);
	if (!(tmp = ft_ctrl_update(fdf)))
		return (-1);
	i = 0;
	while (i < fdf->map->length)
	{
		if ((i % fdf->map->x_max) != 0)
			ft_draw(fdf, tmp[i], tmp[i - 1]);
		if ((i / fdf->map->x_max) != 0)
			ft_draw(fdf, tmp[i], tmp[i - fdf->map->x_max]);
		i++;
	}
	free(tmp);
	mlx_put_image_to_window(fdf->mlx_id, fdf->win_id, fdf->img_id, 0, 0);
	mlx_destroy_image(fdf->mlx_id, fdf->img_id);
	free(fdf->image);
	return (0);
}
