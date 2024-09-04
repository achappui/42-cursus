/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:09:30 by achappui          #+#    #+#             */
/*   Updated: 2024/02/23 14:47:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_comp(unsigned int color, char comp)
{
	if (comp == A)
		return ((float)(color >> 24));
	else if (comp == R)
		return ((float)((color << 8) >> 24));
	else if (comp == G)
		return ((float)((color << 16) >> 24));
	else if (comp == B)
		return ((float)((color << 24) >> 24));
	return (0);
}

unsigned int	lerp(unsigned int color_1, unsigned int color_2, float pos)
{
	return (((unsigned int)(get_comp(color_1, A) + \
			pos * (get_comp(color_2, A) - get_comp(color_1, A))) << 24) | \
			((unsigned int)(get_comp(color_1, R) + \
			pos * (get_comp(color_2, R) - get_comp(color_1, R))) << 16) | \
			((unsigned int)(get_comp(color_1, G) + \
			pos * (get_comp(color_2, G) - get_comp(color_1, G))) << 8) | \
			((unsigned int)(get_comp(color_1, B) + \
			pos * (get_comp(color_2, B) - get_comp(color_1, B)))));
}
