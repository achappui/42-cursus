/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_actions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:50:15 by achappui          #+#    #+#             */
/*   Updated: 2024/02/23 14:54:34 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_and_quit(void *voidargs)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)voidargs;
	mlx_destroy_image(fdf->d.mlx_ptr, fdf->d.img.img);
	mlx_destroy_window(fdf->d.mlx_ptr, fdf->d.win_ptr);
	free(fdf->d.row1);
	free(fdf->d.row2);
	free_map(&fdf->m);
	exit(0);
}

void	change_z_2(t_fdf *fdf, int sign, char *check, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < fdf->m.nb_c)
	{
		if (fdf->m.points[i][j][Z])
		{
			if (fdf->m.points[i][j][Z] + Z_CHANGER * sign == 0)
			{
				*check = 1;
				fdf->m.points[i][j][Z] += 2 * Z_CHANGER * sign;
			}
			else
			{
				*check = 2;
				fdf->m.points[i][j][Z] += Z_CHANGER * sign;
			}
		}
		j++;
	}
}

void	change_z_1(t_fdf *fdf, int sign)
{
	unsigned int	i;
	char			check;

	i = -1;
	check = 0;
	while (++i < fdf->m.nb_l)
		change_z_2(fdf, sign, &check, i);
	if (check == 1)
		fdf->t.height_diff += 2 * Z_CHANGER * sign;
	else if (check == 2)
		fdf->t.height_diff += Z_CHANGER * sign;
	display_map(fdf);
}

void	check_color_change(int key, t_fdf *fdf)
{
	if (key == KEY_1)
	{
		fdf->top_color = 0xF6BF08;
		fdf->bottom_color = 0x1E75C1;
	}
	else if (key == KEY_2)
	{
		fdf->top_color = 0xE473F0;
		fdf->bottom_color = 0x17B226;
	}
	else if (key == KEY_3)
	{
		fdf->top_color = 0xFF3333;
		fdf->bottom_color = 0xFFFFFF;
	}
	add_color_to_nocolor_map(fdf);
	display_map(fdf);
}

int	input_listener(int key, void *args)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)args;
	ft_bzero(fdf->d.img.addr, WINDOW_HEIGHT * WINDOW_WIDTH * \
	(fdf->d.img.bits_per_pixel / 8));
	if (key == KEY_ESC)
		free_and_quit(fdf);
	else if (key == KEY_R)
		reset(fdf);
	else if (key == KEY_SPACE)
		switch_view(fdf);
	else if (key == KEY_PLUS2 && fdf->t.height_diff < 200)
		change_z_1(fdf, 1);
	else if (key == KEY_MINUS2 && fdf->t.height_diff > -200)
		change_z_1(fdf, -1);
	check_rotation(fdf, key);
	check_zoom(fdf, key);
	check_translation(fdf, key);
	if (!fdf->m.any_color)
		check_color_change(key, fdf);
	return (0);
}
