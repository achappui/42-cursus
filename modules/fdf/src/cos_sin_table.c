/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos_sin_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:13:58 by achappui          #+#    #+#             */
/*   Updated: 2024/01/15 21:37:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calcul_table(t_fdf *fdf)
{
	unsigned int	i;
	double			angle;
	double			step;

	i = 0;
	angle = 0;
	step = M_PI_2 / ROTATION_TABLE_SIZE;
	while (i < ROTATION_TABLE_SIZE)
	{
		fdf->t.rot[i] = (int)(1000 * sin(angle + M_PI_2)); //plutot que 1000 faire un multiple de 2 ? genre 1024
		i++;
	}
}

void	calcul_table(t_fdf *fdf)
{
	unsigned int	i;
	double			angle;
	double			step;

	i = 0;
	angle = 0;
	step = M_PI_2 / ROTATION_TABLE_SIZE;
	while (i < ROTATION_TABLE_SIZE)
	{
		fdf->t.rot[i] = (int)(1000 * cos(angle + M_PI));
		i++;
	}
}