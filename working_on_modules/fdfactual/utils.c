/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:24:39 by achappui          #+#    #+#             */
/*   Updated: 2024/02/23 14:59:25 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_ptr(t_point2d **ptr1, t_point2d **ptr2)
{
	t_point2d	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

void	free_map(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (i < map->nb_l)
		free(map->points[i++]);
	free(map->points);
}

void	matrix_pow(t_mat3 matrix1, t_mat3 matrix2, t_mat3 result)
{
	unsigned int	l;
	unsigned int	c;

	l = 0;
	while (l < 3)
	{
		c = 0;
		while (c < 3)
		{
			result[l][c] = \
			matrix1[l][0] * matrix2[0][c] + \
			matrix1[l][1] * matrix2[1][c] + \
			matrix1[l][2] * matrix2[2][c];
			c++;
		}
		l++;
	}
}

void	matrix_copy(t_mat3 dst, t_mat3 src)
{
	unsigned int	l;
	unsigned int	c;

	l = 0;
	while (l < 3)
	{
		c = 0;
		while (c < 3)
		{
			dst[l][c] = src[l][c];
			c++;
		}
		l++;
	}
}

float	start_zoom_factor(t_fdf *fdf)
{
	if (fdf->m.nb_c * fdf->m.nb_l > 100000)
		return (2);
	else if (fdf->m.nb_c * fdf->m.nb_l >= 5000)
		return (4);
	else if (fdf->m.nb_c * fdf->m.nb_l > 1000)
		return (6);
	else if (fdf->m.nb_c * fdf->m.nb_l >= 400)
		return (10);
	return (25);
}
