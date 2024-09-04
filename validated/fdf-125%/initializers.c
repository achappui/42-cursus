/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:02:22 by marvin            #+#    #+#             */
/*   Updated: 2024/01/06 17:02:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initializer_error(t_fdf *fdf, char *message, char err_no)
{
	if (err_no == 1)
		free_map(&fdf->m);
	if (err_no >= 2)
	{
		if (fdf->d.row1)
			free(fdf->d.row1);
		if (fdf->d.row2)
			free(fdf->d.row2);
	}
	if (err_no >= 3)
		mlx_destroy_window(fdf->d.mlx_ptr, fdf->d.win_ptr);
	if (err_no >= 4)
		mlx_destroy_image(fdf->d.mlx_ptr, fdf->d.img.img);
	ft_putendl_fd(message, 2);
	exit(1);
}

static void	center(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < map->nb_l)
	{
		j = -1;
		while (++j < map->nb_c)
		{
			map->points[i][j][X] -= (float)(map->nb_c / 2);
			map->points[i][j][Y] -= (float)(map->nb_l / 2);
		}
	}
}

void	init_map(t_fdf *fdf, int argc, char *argv[])
{
	t_list	parsing_list;
	int		fd;

	fdf->m.any_color = 0;
	fdf->m.nb_c = 0;
	fdf->m.nb_l = 0;
	parsing_list.content = NULL;
	parsing_list.next = NULL;
	check_arguments(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		initializer_error(fdf, "ERROR: could not open the file.", 0);
	parse_file_content(fd, &parsing_list, &parsing_list, &fdf->m);
	if (close(fd) == -1)
		initializer_error(fdf, "ERROR: could not close the file.", 1);
	center(&fdf->m);
}

void	init_display(t_fdf *fdf)
{
	fdf->d.row1 = NULL;
	fdf->d.row2 = NULL;
	fdf->d.row1 = (t_point2d *)malloc(fdf->m.nb_c * sizeof(t_point2d));
	if (!fdf->d.row1)
		initializer_error(fdf, "ERROR: malloc failed", 2);
	fdf->d.row2 = (t_point2d *)malloc(fdf->m.nb_c * sizeof(t_point2d));
	if (!fdf->d.row2)
		initializer_error(fdf, "ERROR: malloc failed", 2);
	fdf->d.mlx_ptr = mlx_init();
	if (!fdf->d.mlx_ptr)
		initializer_error(fdf, "ERROR: mlx_init failed", 2);
	fdf->d.win_ptr = mlx_new_window(fdf->d.mlx_ptr, \
	WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (!fdf->d.win_ptr)
		initializer_error(fdf, "ERROR: mlx_new_window failed", 2);
	fdf->d.img.img = mlx_new_image(fdf->d.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!fdf->d.img.img)
		initializer_error(fdf, "ERROR: mlx_new_image failed", 3);
	fdf->d.img.addr = mlx_get_data_addr(fdf->d.img.img, \
	&fdf->d.img.bits_per_pixel, &fdf->d.img.line_length, &fdf->d.img.endian);
	if (!fdf->d.img.addr)
		initializer_error(fdf, "ERROR: mlx_get_data_addr failed", 4);
}

void	init_transform(t_fdf *fdf)
{
	fdf->t.t_x = WINDOW_WIDTH / 2;
	fdf->t.t_y = WINDOW_HEIGHT / 2;
	fdf->t.zoom = start_zoom_factor(fdf);
	fdf->t.view = 1;
	fdf->t.height_diff = 0;
	set_isomertic_view(fdf);
	set_matrix_to_identity(fdf->t.rotation_matrix);
}
