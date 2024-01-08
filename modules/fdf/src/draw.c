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

void	draw_line(t_fdfpoint *p1, t_fdfpoint *p2)
{
	
}

void	display_figure(t_fdfpoint **points, unsigned int line_len,  unsigned int col_len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < line_len - 1)
	{
		draw_line(&points[j][i], &points[i + 1]);
		i++;
	}
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