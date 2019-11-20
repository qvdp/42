/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:03:14 by qvan-der          #+#    #+#             */
/*   Updated: 2019/10/08 23:20:21 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_pixel(t_env *fdf, int x, int y)
{
	int	*whole_pixels;

	whole_pixels = (int *)fdf->image->pixels;
	if (x > 0 && x < fdf->cam->vw && y > 0 && y < fdf->cam->vh)
		whole_pixels[y * fdf->cam->vw + x] = 0xFFFFFF;
}

void	ft_line_x(t_env *fdf, t_coor start, t_coor end)
{
	int dx;
	int dy;
	int i;

	dx = end.x - start.x;
	dy = end.y - start.y;
	i = 0;
	while (i < dx)
	{
		ft_set_pixel(fdf, start.x + i, start.y + dy * i / dx);
		i++;
	}
}

void	ft_line_y(t_env *fdf, t_coor start, t_coor end)
{
	int dx;
	int dy;
	int i;

	dx = end.x - start.x;
	dy = end.y - start.y;
	i = 0;
	if (dy < 0)
	{
		while (i > dy)
		{
			ft_set_pixel(fdf, start.x + dx * i / dy, start.y + i);
			i--;
		}
	}
	else
	{
		while (i < dy)
		{
			ft_set_pixel(fdf, start.x + dx * i / dy, start.y + i);
			i++;
		}
	}
}

void	ft_draw(t_env *fdf, t_coor start, t_coor end)
{
	if (end.x >= start.x)
	{
		if (ft_abs((end.x - start.x)) >= ft_abs((end.y - start.y)))
			ft_line_x(fdf, start, end);
		else
			ft_line_y(fdf, start, end);
	}
	else if (end.x <= start.x)
	{
		if (ft_abs((end.x - start.x)) >= ft_abs((end.y - start.y)))
			ft_line_x(fdf, end, start);
		else
			ft_line_y(fdf, end, start);
	}
}
