/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:09:30 by achappui          #+#    #+#             */
/*   Updated: 2024/02/23 14:47:39 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_display *d, unsigned int color)
{
	char	*dst;

	if (d->b.y < WINDOW_HEIGHT && d->b.y >= 0 && d->b.x < \
	WINDOW_WIDTH && d->b.x >= 0)
	{
		dst = d->img.addr + \
		(d->b.y * d->img.line_length + d->b.x * (d->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	oct_1(t_point2d p1, t_point2d p2, t_display *d)
{
	d->b.err = -d->b.dx >> 1 ;
	while (d->b.x < p2[X] && ((d->b.x < WINDOW_WIDTH && d->b.x >= 0) || \
	(d->b.y < WINDOW_HEIGHT && d->b.y >= 0)))
	{
		my_mlx_pixel_put(d, lerp((unsigned int)p1[COLOR], \
		(unsigned int)p2[COLOR], (float)(d->b.x - p1[X]) / \
		(float)(p2[X] - p1[X])));
		d->b.err += d->b.dy;
		if (d->b.err > 0)
		{
			d->b.err -= d->b.dx;
			d->b.y++;
		}
		d->b.x++;
	}
}

void	oct_2(t_point2d p1, t_point2d p2, t_display *d)
{
	d->b.err = -d->b.dy >> 1 ;
	while (d->b.y < p2[Y] && ((d->b.x < WINDOW_WIDTH && d->b.x >= 0) || \
	(d->b.y < WINDOW_HEIGHT && d->b.y >= 0)))
	{
		my_mlx_pixel_put(d, lerp((unsigned int)p1[COLOR], \
		(unsigned int)p2[COLOR], (float)(d->b.y - p1[Y]) / \
		(float)(p2[Y] - p1[Y])));
		d->b.err += d->b.dx;
		if (d->b.err > 0)
		{
			d->b.err -= d->b.dy;
			d->b.x++;
		}
		d->b.y++;
	}
}

void	oct_7(t_point2d p1, t_point2d p2, t_display *d)
{
	d->b.err = d->b.dy >> 1 ;
	while (d->b.y > p2[Y] && ((d->b.x < WINDOW_WIDTH && d->b.x >= 0) || \
	(d->b.y < WINDOW_HEIGHT && d->b.y >= 0)))
	{
		my_mlx_pixel_put(d, lerp((unsigned int)p1[COLOR], \
		(unsigned int)p2[COLOR], ((float)(p1[Y] - p2[Y]) - \
		(float)(d->b.y - p2[Y])) / (float)(p1[Y] - p2[Y])));
		d->b.err += d->b.dx;
		if (d->b.err > 0)
		{
			d->b.err += d->b.dy;
			d->b.x++;
		}
		d->b.y--;
	}
}

void	oct_8(t_point2d p1, t_point2d p2, t_display *d)
{
	d->b.err = -d->b.dx >> 1 ;
	while (d->b.x < p2[X] && ((d->b.x < WINDOW_WIDTH && d->b.x >= 0) || \
	(d->b.y < WINDOW_HEIGHT && d->b.y >= 0)))
	{
		my_mlx_pixel_put(d, lerp((unsigned int)p1[COLOR], \
		(unsigned int)p2[COLOR], (float)(d->b.x - p1[X]) / \
		(float)(p2[X] - p1[X])));
		d->b.err -= d->b.dy;
		if (d->b.err > 0)
		{
			d->b.err -= d->b.dx;
			d->b.y--;
		}
		d->b.x++;
	}
}
