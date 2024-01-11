/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:10:15 by achappui          #+#    #+#             */
/*   Updated: 2024/01/10 10:15:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux.h"

typedef struct s_screen_point
{
	int	x;
	int	y;
	int	color;
}	t_screen_point;


void ligne_8(t_screen_point *p1, t_screen_point *p2, void *mlx_ptr, void *win_ptr)
{
    short err, dx, dy;

    dx = x2 - x1 ;
    dy = y2 - y1 ;
    err = -dx >> 1 ;
    x2 = x2 - x1 + 1;

	while (x2-- > 0)
	{
        mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);

        err += dy;
        if(err > 0)
        {
            err -= dx;
            y1++;
        }
        x1++;
	}
}

void ligne_1(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
{
    short err, dx, dy;

    dx = x2 - x1 ;
    dy = y2 - y1 ;
    err = dx >> 1 ;
    x2 = x2 - x1 + 1;

	while (x2-- > 0)
	{
        mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);

        err += dy;
        if(err < 0)
        {
            err += dx;
            y1--;
        }
        x1++;
	}
}

void	choose_one()
{
	if ()
	{
		
	}
}