/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:24:26 by achappui          #+#    #+#             */
/*   Updated: 2024/02/21 15:24:26 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parsing_error(t_list *list, void *to_free, \
char **split_to_free, char *message)
{
	ft_lstclear(&list, &free);
	if (to_free)
		free(to_free);
	if (split_to_free)
		ft_split_free(split_to_free);
	if (!message)
		ft_putendl_fd("ERROR: map is not valid or malloc failed", 2);
	else
		ft_putendl_fd(message, 2);
	exit(1);
}

char	check_sequence(char **split, unsigned int i, \
t_point3d *array, t_map *map)
{
	unsigned int	j;
	long long		valid_z;
	long long		valid_color;

	j = 0;
	valid_color = 0xFFFFFF;
	while (split[i][j] != ',' && split[i][j] != '\0')
		j++;
	if (split[i][j] == ',')
	{
		map->any_color = 1;
		valid_color = validate_integer(split[i] + j + 1);
	}
	split[i][j] = '\0';
	valid_z = validate_integer(split[i]);
	if (valid_color == INVALID || valid_z == INVALID)
		return (0);
	array[i][Z] = (float)valid_z;
	array[i][COLOR] = (float)valid_color;
	return (1);
}

char	fill_points_line(t_point3d *array, char **split, \
unsigned int y, t_map *map)
{
	unsigned int	i;

	i = 0;
	while (split[i] != NULL)
	{
		if (!check_sequence(split, i, array, map))
			return (0);
		array[i][X] = (float)i;
		array[i][Y] = (float)y;
		i++;
	}
	return (1);
}
