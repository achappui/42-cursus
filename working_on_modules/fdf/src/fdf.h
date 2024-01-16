/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:29:16 by marvin            #+#    #+#             */
/*   Updated: 2024/01/06 18:29:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/libft/libft.h"
# define __USE_MISC
# include <math.h>
# include "mlx.h" //aller chercher le mlx.h dans la minilibx et non le copier dans les sources

# define WHITE_SPACES	" \t\n\v\f\r"
# define INVALID		LLONG_MAX

# define KEY_UP		0
# define KEY_DOWN	0
# define KEY_RIGHT	0
# define KEY_LEFT	0
# define KEY_ESC	0
# define KEY_E		0
# define KEY_R		0
# define KEY_Q		0
# define KEY_W		0

# define X	0
# define Y	1
# define Z	2

# define UNIT_3D					1000

# define TRANSLATION_MULTIPLIER		1
# define ROTATION_MULTIPLIER		1
# define SCALE_MULTIPLIER			1

# define TRANSLATION_UNIT		TRANSLATION_MULTIPLIER * UNIT_3D
# define ROTATION_TABLE_SIZE	(1 / ROTATION_MULTIPLIER) * 10
# define SCALE_UNIT				SCALE_MULTIPLIER * UNIT_3D

typedef struct s_fdf
{
	struct s_map		m;
	struct s_transform	t;
	struct s_util		u;
}	t_fdf;

typedef struct s_map
{
	long long		**tab;
	unsigned int	line_len;
	unsigned int	col_len;
}	t_map;

typedef struct s_transform
{
	int	translation[3];
	int	scale; //ajout a x y z, commence a 0
	int	rot_idx;
	int	rot[ROTATION_TABLE_SIZE]; //on a besoin de juste un quart de cercle et sin et cos sont juste decaler de 90 degre
}	t_transform;

typedef struct s_util
{
	void					*mlx_ptr;
	void					*win_ptr;
	struct s_screen_point	*prev_line;
	struct s_screen_point	*line;
	struct s_data			*data;
}	t_util;

typedef struct s_screen_point
{
	int				x;
	int				y;
	unsigned int	a;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_screen_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	swap_ptr(void **ptr1, void **ptr2);
void		link_using_bresenham(t_screen_point *p1, t_screen_point *p2, t_util *u);

void		error_handler_parsing(t_list *list, void *to_free, char **split_to_free);
long long	validate_int(const char *s);
void		input_handler(int argc, char *argv[], t_map *inputs);
void		parse_file_content(int fd, t_list *begin, t_list *list, t_map *inputs);

#endif