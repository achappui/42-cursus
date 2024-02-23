/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:43:38 by achappui          #+#    #+#             */
/*   Updated: 2024/02/23 14:56:10 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_commands(void)
{
	ft_printf("COMMANDS:\n");
	ft_printf("Rotate X --> Q and A\n");
	ft_printf("Rotate Y --> W and S\n");
	ft_printf("Rotate Z --> E and D\n");
	ft_printf("Change height --> + and -\n");
	ft_printf("ZOOM --> + and - (on numpad)\n");
	ft_printf("Change view --> space\n");
	ft_printf("RESET --> R\n");
	ft_printf("Change colors --> 1, 2 or 3\n");
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	init_map(&fdf, argc, argv);
	if (!fdf.m.any_color)
	{
		fdf.bottom_color = 0x1E75C1;
		fdf.top_color = 0xF6BF08;
		add_color_to_nocolor_map(&fdf);
	}
	init_display(&fdf);
	init_transform(&fdf);
	display_map(&fdf);
	print_commands();
	mlx_hook(fdf.d.win_ptr, 2, 0, &input_listener, &fdf);
	mlx_hook(fdf.d.win_ptr, 17, 0, &free_and_quit, &fdf);
	mlx_loop(fdf.d.mlx_ptr);
	return (0);
}
