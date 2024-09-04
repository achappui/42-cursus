/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_actions_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:23:37 by achappui          #+#    #+#             */
/*   Updated: 2024/02/23 14:55:55 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update_local_matrix(t_mat3 rotation_matrix, t_mat3 local_matrix)
{
	t_mat3	result;

	matrix_pow(rotation_matrix, local_matrix, result);
	matrix_copy(local_matrix, result);
}

void	set_matrix_to_identity(t_mat3 m)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m[i][j] = 0;
	}
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
}

void	set_isomertic_view(t_fdf *fdf)
{
	set_matrix_to_identity(fdf->t.local_matrix);
	rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, X, -1);
	rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, X, -1);
	rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, Z, 1);
	rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, Z, 1);
}

void	set_top_view(t_mat3 local_matrix)
{
	set_matrix_to_identity(local_matrix);
}

void	rotation(t_mat3 rotation_matrix, t_mat3 local_matrix, \
char axe, char sign)
{
	set_matrix_to_identity(rotation_matrix);
	if (axe == X)
	{
		rotation_matrix[0][0] = cos(ROTATION_ANGLE * sign);
		rotation_matrix[0][1] = -sin(ROTATION_ANGLE * sign);
		rotation_matrix[1][0] = sin(ROTATION_ANGLE * sign);
		rotation_matrix[1][1] = cos(ROTATION_ANGLE * sign);
	}
	else if (axe == Y)
	{
		rotation_matrix[0][0] = cos(ROTATION_ANGLE * sign);
		rotation_matrix[0][2] = sin(ROTATION_ANGLE * sign);
		rotation_matrix[2][0] = -sin(ROTATION_ANGLE * sign);
		rotation_matrix[2][2] = cos(ROTATION_ANGLE * sign);
	}
	else if (axe == Z)
	{
		rotation_matrix[1][1] = cos(ROTATION_ANGLE * sign);
		rotation_matrix[1][2] = -sin(ROTATION_ANGLE * sign);
		rotation_matrix[2][1] = sin(ROTATION_ANGLE * sign);
		rotation_matrix[2][2] = cos(ROTATION_ANGLE * sign);
	}
	update_local_matrix(rotation_matrix, local_matrix);
}
