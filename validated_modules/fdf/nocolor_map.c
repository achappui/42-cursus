/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nocolor_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:23:50 by achappui          #+#    #+#             */
/*   Updated: 2024/02/23 15:09:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_highest_z(t_map *map)
{
	unsigned int	i;
	unsigned int	j;
	int				highest_z;

	highest_z = map->points[0][0][Z];
	i = -1;
	while (++i < map->nb_l)
	{
		j = -1;
		while (++j < map->nb_c)
			if (map->points[i][j][Z] > highest_z)
				highest_z = map->points[i][j][Z];
	}
	return (highest_z);
}

int	get_lowest_z(t_map *map)
{
	unsigned int	i;
	unsigned int	j;
	int				lowest_z;

	lowest_z = map->points[0][0][Z];
	i = -1;
	while (++i < map->nb_l)
	{
		j = -1;
		while (++j < map->nb_c)
			if (map->points[i][j][Z] < lowest_z)
				lowest_z = map->points[i][j][Z];
	}
	return (lowest_z);
}

void	add_colors(t_fdf *fdf, int lowest_z, int highest_z)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < fdf->m.nb_l)
	{
		j = -1;
		while (++j < fdf->m.nb_c)
			fdf->m.points[i][j][COLOR] = lerp(fdf->bottom_color, \
			fdf->top_color, (float)(fdf->m.points[i][j][Z] - lowest_z) \
			/ (float)(highest_z - lowest_z));
	}
}

void	add_color_to_nocolor_map(t_fdf *fdf)
{
	int	lowest_z;
	int	highest_z;

	lowest_z = get_lowest_z(&fdf->m);
	highest_z = get_highest_z(&fdf->m);
	if (lowest_z == highest_z)
		highest_z = lowest_z + 1;
	add_colors(fdf, lowest_z, highest_z);
}
