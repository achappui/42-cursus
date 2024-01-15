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

void	end_program(t_fdf *fdf)
{

	exit(0);
}

int	key_hook(int key, t_fdf *fdf)
{
	if (key == KEY_UP)
		fdf->t.translation[Y]--;
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
		end_program(fdf);
	else
		return (0);
	display_figure(fdf);
	return (0);
}

void	init_fdf_struct(t_fdf *fdf)
{
	fdf->m.col_len = 0;
	fdf->m.line_len = 0;
	fdf->m.tab = NULL;
	fdf->t.rot_idx = 0;
	fdf->t.scale = 0;
	fdf->t.translation[X] = 0;
	fdf->t.translation[Y] = 0;
	fdf->t.translation[Z] = 0;
	calcul_table(fdf->t.cos_t); //a changer
	fdf->u.mlx_ptr = NULL;
	fdf->u.win_ptr = NULL;
	fdf->u.line = NULL;
	fdf->u.prev_line = NULL;
}

void	free_all(t_fdf *fdf)
{
	unsigned int	i;

	i = 0;
	while (i < fdf->m.col_len)
		free(fdf->m.tab[i++]);
	if (fdf->m.tab)
		free(fdf->m.tab);
	if (fdf->u.line)
		free(fdf->u.line);
	if (fdf->u.prev_line)
		free(fdf->u.prev_line);
}

void	prepare_utils(t_fdf *fdf)
{
	fdf->u.line = (t_util *)malloc(fdf->m.line_len * sizeof(t_util));
	if (!fdf->u.line)
	{
		free_all(fdf);
		ft_putendl_fd("ERROR: malloc failed\n", 2);
		exit(1);
	}
	fdf->u.prev_line = (t_util *)malloc(fdf->m.line_len * sizeof(t_util));
	if (!fdf->u.line)
	{
		free_all(fdf);
		ft_putendl_fd("ERROR: malloc failed\n", 2);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	init_fdf_struct(&fdf);
	input_handler(argc, argv, &fdf.m);
	prepare_utils(&fdf);
	fdf.u.mlx_ptr = mlx_init();
	if (!fdf.u.mlx_ptr)
		
	fdf.u.win_ptr = mlx_new_window(fdf.u.mlx_ptr, 500, 500, "salut");
	if (!fdf.u.win_ptr)



	mlx_key_hook(fdf.u.mlx_ptr, &key_hook, &fdf);
	mlx_loop(fdf.u.mlx_ptr);
	free_all(&fdf);
	return (0);
}


void	print_map(t_fdf *fdf)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < fdf->m.col_len)
	{
		j = 0;
		while (j < fdf->m.line_len)
		{
			ft_printf("%d,%X ", (int)(fdf->m.tab[i][j] >> 32), (unsigned int)(fdf->m.tab[i][j]));
			j++;
		}
		ft_printf("\n");
		i++;
	}
}