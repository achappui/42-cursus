/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:57:09 by achappui          #+#    #+#             */
/*   Updated: 2024/01/28 12:06:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



typedef double	t_vec3[3]; //stocker la color dans un 4em ou 5em element, sans oublier homogeneous coordinates

// typedef struct s_point3d
// {
// 	t_vec3			*points;

// }	t_point3d;

typedef struct s_map
{
	unsigned int	line_len;
	t_vec3			*points;
	double			local_transform_matrix[4][4];
	double			world_transform_matrix[4][4];
}	t_map;

typedef struct s_camera
{
	double	local_transform_matrix[4][4];
	double	world_transform_matrix[4][4];
	double	view_matrix[4][4];
	double	projection_matrix[4][4];
}	t_camera;

typedef struct s_matrix
{
	double	trans_x[4][4];
	double	trans_y[4][4];
	double	trans_z[4][4];
	double	rot_x[4][4];
	double	rot_y[4][4];
	double	rot_z[4][4];
	double	scale_x[4][4];
	double	scale_y[4][4];
	double	scale_z[4][4];
}	t_matrix;