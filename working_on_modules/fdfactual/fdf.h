/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:51:33 by achappui          #+#    #+#             */
/*   Updated: 2024/02/23 14:54:07 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define Z_CHANGER		1
# define WINDOW_HEIGHT		1000
# define WINDOW_WIDTH		1000
# define ROTATION_ANGLE		0.39269908169f
# define TRANSLATION_UNIT	20
# define WHITE_SPACES		" \t\n\v\f\r"
# define INVALID			LLONG_MAX
# define KEY_ESC			53
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_LEFT			123
# define KEY_Q				12
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_E				14
# define KEY_D				2
# define KEY_PLUS			69
# define KEY_MINUS			78
# define KEY_R				15
# define KEY_SPACE			49
# define KEY_MINUS2			27
# define KEY_PLUS2			24
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define COLOR	0
# define X		1
# define Y		2
# define Z		3
# define A		1
# define R		2
# define G		3
# define B		4

typedef float	t_mat3[3][3];
typedef float	t_point3d[4];
typedef int		t_point2d[3];

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_bresenham
{
	unsigned int	pixel_nb;
	int				err;
	int				dx;
	int				dy;
	int				x;
	int				y;
}	t_bresenham;

typedef struct s_map
{
	unsigned int	nb_l;
	unsigned int	nb_c;
	t_point3d		**points;
	char			any_color;
}	t_map;

typedef struct s_display
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point2d	*row1;
	t_point2d	*row2;
	t_bresenham	b;
	t_img		img;
}	t_display;

typedef struct s_transform
{
	int			t_x;
	int			t_y;
	float		zoom;
	int			height_diff;
	t_mat3		local_matrix;
	t_mat3		rotation_matrix;
	char		view;
}	t_transform;

typedef struct s_fdf
{
	t_map			m;
	t_display		d;
	t_transform		t;
	unsigned int	top_color;
	unsigned int	bottom_color;
}	t_fdf;

void			switch_view(t_fdf *fdf);
void			reset(t_fdf *fdf);
unsigned int	lerp(unsigned int color_1, unsigned int color_2, float pos);
void			add_color_to_nocolor_map(t_fdf *fdf);
int				free_and_quit(void *voidargs);
float			start_zoom_factor(t_fdf *fdf);
char			fill_points_line(t_point3d *array, char **split, \
unsigned int y, t_map *map);
void			display_map(t_fdf *fdf);
void			oct_1(t_point2d p1, t_point2d p2, t_display *d);
void			oct_2(t_point2d p1, t_point2d p2, t_display *d);
void			oct_7(t_point2d p1, t_point2d p2, t_display *d);
void			oct_8(t_point2d p1, t_point2d p2, t_display *d);
void			init_map(t_fdf *fdf, int argc, char *argv[]);
void			init_display(t_fdf *fdf);
void			init_transform(t_fdf *fdf);
int				input_listener(int key, void *args);
void			check_rotation(t_fdf *fdf, int key);
void			check_translation(t_fdf *fdf, int key);
void			check_zoom(t_fdf *fdf, int key);
void			set_matrix_to_identity(t_mat3 m);
void			set_isomertic_view(t_fdf *fdf);
void			set_top_view(t_mat3 local_matrix);
void			rotation(t_mat3 rotation_matrix, t_mat3 local_matrix, \
char axe, char sign);
void			parse_file_content(int fd, t_list *begin, t_list *list, \
t_map *map);
void			check_arguments(int argc, char *argv[]);
void			parsing_error(t_list *list, void *to_free, \
char **split_to_free, char *message);
void			remove_gnl_eol(char *line);
long long		validate_integer(const char *s);
void			swap_ptr(t_point2d **ptr1, t_point2d **ptr2);
void			free_map(t_map *map);
void			matrix_pow(t_mat3 matrix1, t_mat3 matrix2, t_mat3 result);
void			matrix_copy(t_mat3 dst, t_mat3 src);
#endif
