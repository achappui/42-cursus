/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:39:09 by achappui          #+#    #+#             */
/*   Updated: 2024/01/15 19:00:11 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_figure(t_fdf *fdf)
{
	unsigned int	line_i;

	line_i = 0;
	calcul_line(fdf, line_i);
	link_line(fdf);
	while (line_i < fdf->m.col_len)
	{
		swap_ptr(&fdf->u.prev_line, &fdf->u.line);
		calcul_line(fdf, line_i);
		link_line(fdf);
		link_line_with_prev_line(fdf);
		line_i++;
	}
	mlx_put_image_to_window(fdf->u.mlx_ptr, fdf->u.win_ptr, fdf->u.data->img, 0, 0);
}

void	link_line(t_fdf *fdf)
{
	unsigned int	i;

	i = 0;
	while (i < fdf->m.line_len - 1)
	{
		link_using_bresenham(&fdf->u.line[i], &fdf->u.line[i + 1], &fdf->u);
		i++;
	}
}

void	link_line_with_prev_line(t_fdf *fdf)
{
	unsigned int	i;

	i = 0;
	while (i < fdf->m.line_len)
	{
		link_using_bresenham(&fdf->u.line[i], &fdf->u.prev_line[i], &fdf->u);
		i++;
	}
}