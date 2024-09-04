/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_actions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:54:14 by achappui          #+#    #+#             */
/*   Updated: 2024/02/21 15:54:14 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_rotation(t_fdf *fdf, int key)
{
	char	check;

	check = 0;
	if (key == KEY_A && ++check)
		rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, X, -1);
	else if (key == KEY_Q && ++check)
		rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, X, 1);
	else if (key == KEY_S && ++check)
		rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, Y, -1);
	else if (key == KEY_W && ++check)
		rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, Y, 1);
	else if (key == KEY_D && ++check)
		rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, Z, -1);
	else if (key == KEY_E && ++check)
		rotation(fdf->t.rotation_matrix, fdf->t.local_matrix, Z, 1);
	if (check)
		display_map(fdf);
}

void	check_translation(t_fdf *fdf, int key)
{
	char	check;

	check = 0;
	if (key == KEY_UP && fdf->t.t_y < INT_MAX && ++check)
		fdf->t.t_y += TRANSLATION_UNIT;
	else if (key == KEY_DOWN && fdf->t.t_y > INT_MIN && ++check)
		fdf->t.t_y -= TRANSLATION_UNIT;
	else if (key == KEY_LEFT && fdf->t.t_x < INT_MAX && ++check)
		fdf->t.t_x += TRANSLATION_UNIT;
	else if (key == KEY_RIGHT && fdf->t.t_y > INT_MIN && ++check)
		fdf->t.t_x -= TRANSLATION_UNIT;
	if (check)
		display_map(fdf);
}

void	check_zoom(t_fdf *fdf, int key)
{
	char	check;

	check = 0;
	if (key == KEY_PLUS && fdf->t.zoom < 10000 && ++check)
		fdf->t.zoom++;
	else if (key == KEY_MINUS && fdf->t.zoom > 0 && ++check)
		fdf->t.zoom--;
	if (check)
		display_map(fdf);
}

void	reset(t_fdf *fdf)
{
	unsigned int	i;
	unsigned int	j;

	fdf->t.t_x = WINDOW_WIDTH / 2;
	fdf->t.t_y = WINDOW_HEIGHT / 2;
	fdf->t.zoom = start_zoom_factor(fdf);
	fdf->t.view = 1;
	i = -1;
	while (++i < fdf->m.nb_l)
	{
		j = -1;
		while (++j < fdf->m.nb_c)
			if (fdf->m.points[i][j][Z])
				fdf->m.points[i][j][Z] -= fdf->t.height_diff;
	}
	fdf->t.height_diff = 0;
	set_isomertic_view(fdf);
	set_matrix_to_identity(fdf->t.rotation_matrix);
	display_map(fdf);
}

void	switch_view(t_fdf *fdf)
{
	if (fdf->t.view == 1)
	{
		fdf->t.view = 2;
		set_top_view(fdf->t.local_matrix);
	}
	else
	{
		fdf->t.view = 1;
		set_isomertic_view(fdf);
	}
	display_map(fdf);
}
