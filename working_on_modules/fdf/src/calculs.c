/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:23:25 by achappui          #+#    #+#             */
/*   Updated: 2024/01/15 21:39:24 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	apply_transform()
// {

// }

void	calcul_line(t_fdf *fdf, unsigned int line_i)
{
	int				tmp_point[3];
	unsigned int	i;

	i = 0;
	while (i < fdf->m.line_len)
	{
		tmp_point[X] = i - fdf.;
		tmp_point[Y] = line_i - fdf->t.center_x_y[Y];
		tmp_point[Z] = fdf->m.tab[line_i][i] ;

		
		apply_rotation(tmp_point);
		apply_translation();
		apply_scale();
	}
}