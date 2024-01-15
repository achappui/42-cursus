/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:28:57 by marvin            #+#    #+#             */
/*   Updated: 2024/01/06 18:28:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdfpoint *p1, t_fdfpoint *p2)
{
	
}

void	display_figure(t_fdfpoint **points, unsigned int line_len,  unsigned int col_len)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	while (i < line_len - 1)
		draw_line(&points[j][i], &points[i + 1]);
	j++;
	while (j < col_len)
	{
		i = 0;
		while (i < line_len - 1)
		{
			draw_line(&points[j][i], &points[j][i + 1]);
			draw_line(&points[j][i], &points[j - 1][i]);
			i++;
		}
		draw_line(&points[j][i], &points[j - 1][i]);
		j++;
	}
}

void	calcul_line(t_fdf *fdf, int tmp_point[3])
{
	//static int	tmp_point[3];
	

}

void	apply_transform()
{

}

int	key_hook(int key, t_fdf *fdf)
{
	if (key == KEY_UP)
		fdf->translation[Y]--;
	else if (key == KEY_DOWN)
		fdf->translation[Y]++;
	else if (key == KEY_RIGHT)
		fdf->translation[X]++;
	else if (key == KEY_LEFT)
		fdf->translation[X]--;
	else if (key == KEY_E)
		fdf->table_idx = (fdf->table_idx + 1) % fdf->table_size;
	else if (key == KEY_R)
		fdf->table_idx = (fdf->table_idx + fdf->table_size - 1) % fdf->table_size;
	else if (key == KEY_Q)
		fdf->scale += SCALE_AMOUNT;
	else if (key == KEY_W)
		fdf->scale -= SCALE_AMOUNT;
	else if (key == KEY_ESC)
		exit(0);
	else
		return (0);
	display_figure(fdf);
	return (0);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->m.col_len = 0;
	fdf->m.line_len = 0;
	fdf->m.tab = NULL;
	fdf->t.rot_idx = 0;
	fdf->t.scale = 0;
	fdf->t.translation[X] = 0;
	fdf->t.translation[Y] = 0;
	fdf->t.translation[Z] = 0;
	calcul_cos_table(fdf->t.cos_t);
	calcul_sin_table(fdf->t.sin_t);
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	init_fdf(&fdf);
	input_handler(argc, argv, &fdf.m);
	// unsigned int	i;
	// i = 0;
	// unsigned int	j;
	// while (i < inputs.col_len)
	// {
	// 	j = 0;
	// 	while (j < inputs.line_len)
	// 	{
	// 		printf("%d,%X ", (int)(inputs.map[i][j] >> 32), (unsigned int)(inputs.map[i][j]));
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
	free_inputs(&inputs);
	return (0);
}