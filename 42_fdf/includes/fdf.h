/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 20:39:25 by qvan-der          #+#    #+#             */
/*   Updated: 2019/10/17 20:51:46 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define E_FILE_READ "An error occured while reading map file."
# define E_FILE_CONTENT "Content of map file doesn't respect restrictions."
# define E_ARGUMENTS "Fdf needs a map file as first argument."
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_coor
{
	double			x;
	double			y;
	double			z;
}					t_coor;

typedef struct		s_map
{
	int				x_max;
	int				y_max;
	int				z_min;
	int				z_max;
	int				length;
	t_coor			**coors;
}					t_map;

typedef struct		s_image
{
	char			*pixels;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
}					t_image;

typedef struct		s_cam
{
	int				vw;
	int				vh;
	int				h_trans;
	int				v_trans;
	double			a_x;
	double			a_y;
	double			a_z;
	int				proj;
	int				scale;
}					t_cam;

typedef struct		s_env
{
	void			*mlx_id;
	void			*win_id;
	void			*img_id;
	struct s_map	*map;
	struct s_cam	*cam;
	struct s_image	*image;
	struct s_env	*next;
}					t_env;

int					ft_build_map(char *from_path, t_env *fdf);
int					ft_fdf(t_env *fdf);
int					ft_init_cam(t_env *fdf);
int					ft_key_move(int keycode, t_env *fdf);
int					ft_freearr(char **arr);
int					ft_check(int argc, char **argv);
int					ft_create_image(t_env *fdf);
void				ft_draw(t_env *fdf, t_coor start, t_coor end);

#endif
