/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:54:36 by achappui          #+#    #+#             */
/*   Updated: 2024/02/13 10:54:36 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_line(t_point2d *p1, t_point2d *p2, t_display *d)
{
	if ((*p2)[X] < (*p1)[X])
		swap_ptr(&p1, &p2);
	d->b.x = (*p1)[X];
	d->b.y = (*p1)[Y];
	d->b.dx = (*p2)[X] - (*p1)[X];
	d->b.dy = (*p2)[Y] - (*p1)[Y];
	if ((*p2)[Y] < (*p1)[Y])
	{
		if ((*p2)[X] - (*p1)[X] >= -((*p2)[Y] - (*p1)[Y]))
			oct_8((*p1), (*p2), d);
		else
			oct_7((*p1), (*p2), d);
	}
	else
	{
		if (((*p2)[X] - (*p1)[X]) >= ((*p2)[Y] - (*p1)[Y]))
			oct_1((*p1), (*p2), d);
		else
			oct_2((*p1), (*p2), d);
	}
}

static void	calcul_2d_point(t_fdf *fdf, t_point3d p, unsigned int i)
{
	fdf->d.row1[i][X] = (fdf->t.local_matrix[0][0] * p[X] + \
	fdf->t.local_matrix[0][1] * p[Y] + fdf->t.local_matrix[0][2] * \
	p[Z]) * fdf->t.zoom + fdf->t.t_x;
	fdf->d.row1[i][Y] = (fdf->t.local_matrix[1][0] * p[X] + \
	fdf->t.local_matrix[1][1] * p[Y] + fdf->t.local_matrix[1][2] * \
	p[Z]) * fdf->t.zoom + fdf->t.t_y;
	fdf->d.row1[i][COLOR] = p[COLOR];
}

void	display_map(t_fdf *fdf)
{
	unsigned int	i;
	unsigned int	j;

	j = -1;
	while (++j < fdf->m.nb_l)
	{
		i = -1;
		while (++i < fdf->m.nb_c)
			calcul_2d_point(fdf, fdf->m.points[j][i], i);
		i = -1;
		if (j > 0)
			while (++i < fdf->m.nb_c)
				pixel_line(&fdf->d.row1[i], &fdf->d.row2[i], &fdf->d);
		i = -1;
		while (++i < fdf->m.nb_c - 1)
			pixel_line(&fdf->d.row1[i], &fdf->d.row1[i + 1], &fdf->d);
		swap_ptr(&fdf->d.row1, &fdf->d.row2);
	}
	mlx_put_image_to_window(fdf->d.mlx_ptr, fdf->d.win_ptr, \
	fdf->d.img.img, 0, 0);
}
