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

void	choose_bresenham(t_screen_point *p1, t_screen_point *p2)
{
	if ()
}


void ligne_8(t_screen_point *p1, t_screen_point *p2)
{
	short	err;
	short	dx;
	short	dy;
	short	s_a;
	short	s_r;
	short	s_g;
	short	s_b;

    dx = p2->x - p1->x ;
    dy = p2->y - p1->y ;
    err = -dx >> 1 ;
    p2->x = p2->x - p1->x + 1;
	while (p2->x-- > 0)
	{
        mlx_pixel_put(mlx_ptr, win_ptr, p1->x, p1->y, 0xFFFFFF);
        err += dy;
        if(err > 0)
        {
            err -= dx;
            p1->y++;
        }
        p1->x++;
	}
}

void ligne_1(t_screen_point *p1, t_screen_point *p2)
{
	short	err;
	short	dx;
	short	dy;

    dx = x2 - x1 ;
    dy = y2 - y1 ;
    err = dx >> 1 ;
    x2 = x2 - x1 + 1;
	while (x2-- > 0)
	{
        mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, p1->color);
        err += dy;
        if(err < 0)
        {
            err += dx;
            y1--;
        }
        x1++;
	}
}



// void ligne_8(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
// {
//     short err, dx, dy;

//     dx = x2 - x1 ;
//     dy = y2 - y1 ;
//     err = -dx >> 1 ;
//     x2 = x2 - x1 + 1;

// 	while (x2-- > 0)
// 	{
// 		*(unsigned int*)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))) = color;

//         err += dy;
//         if(err > 0)
//         {
//             err -= dx;
//             y1++;
//         }
//         x1++;
// 	}
// }