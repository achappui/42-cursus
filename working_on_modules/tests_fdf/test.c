//#include "mlx.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_free {
	void	*mlx_ptr;
	void	*img;
	void	*win_ptr;
}	t_free;

// void ligne(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
// {
// 	float	a;
// 	float	b;
//     a = (float)(y2 - y1) / (float)(x2 - x1);
// 	b = y1 - a * x1;
// 	while (x1 < x2)
// 	{
// 		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
// 		if (a * x1 + b - y1 > 0.5)
// 			y1++;
// 		x1++;
// 	}

// }

// void ligne_8(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
// {
//     float err, a;
//     short dx,dy;
//     dx = x2 - x1 ;
//     dy = y2 - y1 ;
//     a = (float)dy / (float)dx ;
// 	x2 = x2 - x1 + 1;
//     err = 0 ;
// 	while (x2--)
// 	{
//         mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
//         err += a ;
//         if(err > 0.5)
//         {
//             err -= 1 ;
//             y1++ ;
//         }

//         x1++ ;	
// 	}
// }

// void	choose_bresenham()
// {
// 	if ()
// }


void oct_8(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
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

void oct_1(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
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

void oct_2(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
{
    short err, dx, dy;

    dx = x2 - x1 ;
    dy = y2 - y1 ;
    err = dy >> 1 ;
    y2 = y1 - y2 + 1;

	while (y2-- > 0)
	{
        mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);

        err += dx;
        if(err > 0)
        {
            err += dy;
            x1++;
        }
        y1--;
	}
}

void oct_7(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
{
    short err, dx, dy;

    dx = x2 - x1 ;
    dy = y2 - y1 ;
    err = -dy >> 1 ;
    y2 = y2 - y1 + 1;

	while (y2-- > 0)
	{
        mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);

        err += dx;
        if(err > 0)
        {
            err -= dy;
            x1++;
        }
        y1++;
	}
}



// void ligne_2(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
// {
//     short err, dx, dy;

//     dx = x2 - x1 ;
//     dy = y2 - y1 ;
//     err = -dy >> 1 ;
//     y2 = y2 - y1 + 1;

// 	while (y2-- > 0)
// 	{
//         mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);

//         err += dx;
//         if(err > 0)
//         {
//             err += dy;
//             x1--;
//         }
//         y1++;
// 	}
// }


// void	choose_algo()
// {

// 	if ()
// 	{
// 		if ()
// 		{
// 			if ()
// 			{

// 			}
// 			else
// 			{
				
// 			}
// 		}
// 		else
// 		{

// 		}
// 	}
// 	else
// 	{
// 		if ()
// 		{

// 		}
// 	}



// }


// void	fonc_display()
// {
// 	make_final_multiplier_matrice(); //qui regroupe les operations de translate, de rotate et de zoom; a appliquer a chaque points
// 	while (points)
// 	{
// 		calcul_point_pos();
// 		put_point_in_image();
// 	}
// 	put_image_on_screen();
// }




// void ligne_1(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
// {
//     short err, dx, dy;

//     dx = x2 - x1 ;
//     dy = y2 - y1 ;
//     err = dx >> 1 ;
//     x2 = x2 - x1 + 1;

// 	while (x2-- > 0)
// 	{
//         mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);

//         err += dy;
//         if(err < 0)
//         {
//             err += dx;
//             y1--;
//         }
//         x1++;
// 	}
// }



// void ligne2(short x1,short y1,short x2,short y2, void *mlx_ptr, void *win_ptr)
// {
//     short err, dx, dy;

//     dx = x2 - x1 ;
//     dy = y2 - y1 ;
//     err = -dx >> 1 ;
//     x2 = x2 - x1 + 1;

// 	while (x2-- > 0)
// 	{
//         mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);

//         err -= dy;
//         if(err > 0)
//         {
//             err -= dx;
//             y1--;
//         }
//         x1++;
// 	}
// }

int get_key(int key, t_free *param)
{
    printf("keynum: %d\n", key);
	(void)param;
	if (key == 53)
	{
		printf("yoo\n");
		mlx_destroy_image(param->mlx_ptr, param->img);
		//mlx_clear_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		
		exit(0);
	}
    return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()	
{
	void    *mlx_ptr;
    void    *win_ptr;
	t_free	param;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "salut");
    //mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);

	//x
	oct_8(250, 250, 280, 260, mlx_ptr, win_ptr); //8em octant
	oct_1(250, 250, 280, 240, mlx_ptr, win_ptr); //1er octant
	oct_7(250, 250, 260, 280, mlx_ptr, win_ptr); //8em octant
	oct_2(250, 250, 260, 220, mlx_ptr, win_ptr); //8em octant

	// //y
	// ligne2(250, 250, 280, 240, mlx_ptr, win_ptr);
	// ligne2(250, 250, 280, 240, mlx_ptr, win_ptr);
	// ligne2(250, 250, 280, 240, mlx_ptr, win_ptr);
	// ligne2(250, 250, 280, 240, mlx_ptr, win_ptr);







	// t_data	img;
	// img.img = mlx_new_image(mlx_ptr, 500, 500);

	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x0000FF00);
	// my_mlx_pixel_put(&img, 6, 5, 0x0000FF00);
	// my_mlx_pixel_put(&img, 5, 6, 0x0000FF00);
	// my_mlx_pixel_put(&img, 6, 6, 0x0000FF00);

	// mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	// param.img = img.img;
	// param.mlx_ptr = mlx_ptr;
	// param.win_ptr = win_ptr;
	mlx_mouse_hook(win_ptr, &get_key, &param);
    mlx_loop(mlx_ptr);
    return (0);
}