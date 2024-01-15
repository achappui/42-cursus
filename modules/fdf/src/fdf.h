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
# include "mlx.h"

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


# define NO_FLOAT_MULTIPLIER	1000
# define TRANSLATION_AMOUNT		
# define ROTATION_TABLE_SIZE	10
# define SCALE_AMOUNT			2

typedef struct s_fdf
{
	t_map		m;
	t_transform	t;
	t_util		u;
}	t_fdf;

typedef struct s_map
{
	long long		**tab;
	unsigned int	line_len;
	unsigned int	col_len;
}	t_map;

typedef struct s_fdftransform
{
	int			translation[3];
	int			scale; //ajout a x y z, commence a 0
	int			rot_idx;
	int			rot[ROTATION_TABLE_SIZE]; //on a besoin de juste un quart de cercle et sin et cos sont juste decaler de 90 degre
}	t_transform;

typedef struct s_utils
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_screen_point	*prev_line;
	t_screen_point	*line;
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



void		error_handler_parsing(t_list *list, void *to_free, char **split_to_free);
long long	validate_int(const char *s);
void		input_handler(int argc, char *argv[], t_map *inputs);
void		parse_file_content(int fd, t_list *begin, t_list *list, t_map *inputs);

#endif