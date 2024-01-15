/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:04:02 by marvin            #+#    #+#             */
/*   Updated: 2024/01/06 19:04:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void ligne_8(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
{
    short err, dx, dy;

    dx = x2 - x1 ;
    dy = y2 - y1 ;
    err = -dx >> 1 ;
    x2 = x2 - x1 + 1;

	while (x2-- > 0)
	{
		*(unsigned int*)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))) = color;

        err += dy;
        if(err > 0)
        {
            err -= dx;
            y1++;
        }
        x1++;
	}
}