/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:02:49 by qvan-der          #+#    #+#             */
/*   Updated: 2019/10/15 22:16:38 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_parse_file(char *from_path, t_list **lst)
{
	int		fd;
	int		ret;
	char	*line;
	t_list	*tmp;

	if ((fd = open(from_path, O_RDONLY)) == -1)
		return (-1);
	while ((ret = ft_get_next_line(fd, &line)))
	{
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		ft_lstadd(lst, tmp);
		ft_strdel(&line);
	}
	ft_lstrev(lst);
	return (0);
}

t_map		*ft_create_empty_map(int x_max, int y_max)
{
	t_map	*map;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->x_max = x_max;
	map->y_max = y_max;
	map->z_min = 0;
	map->z_max = 0;
	map->length = x_max * y_max;
	if (!(map->coors = ft_memalloc(sizeof(t_coor*) * map->length)))
	{
		free(map);
		return (NULL);
	}
	return (map);
}

t_coor		*ft_create_point(int x, int y, char *str)
{
	t_coor	*point;

	if (!(point = (t_coor*)ft_memalloc(sizeof(t_coor))))
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = ft_atoi(str);
	return (point);
}

int			ft_fill_map(int x_max, int y_max, t_list *lst, t_env *fdf)
{
	t_list	*tmp;
	char	**split;
	int		x;
	int		y;

	y = 0;
	while (y < y_max)
	{
		x = -1;
		split = ft_strsplit(lst->content, ' ');
		while (++x < x_max)
			fdf->map->coors[y * x_max + x] = ft_create_point(x, y, split[x]);
		ft_freearr(split);
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
		y++;
	}
	return (1);
}

int			ft_build_map(char *from_path, t_env *fdf)
{
	int			i;
	t_list		*lst;
	char		**split;

	lst = NULL;
	ft_parse_file(from_path, &lst);
	split = ft_strsplit(lst->content, ' ');
	fdf->map = ft_create_empty_map(ft_arrlen(split), ft_lstlen(lst));
	ft_fill_map(ft_arrlen(split), ft_lstlen(lst), lst, fdf);
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (0);
}
