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

void	check_arguments(int argc, char *argv[])
{
	size_t	len;

	if (argc < 2 || argc > 2)
	{
		ft_putendl_fd("ERROR: you must enter exactly one map.", 2);
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (len < 4 || !(argv[1][len - 1] == 'f' && argv[1][len - 2] == 'd' && \
					argv[1][len - 3] == 'f' && argv[1][len - 4] == '.'))
	{
		ft_putendl_fd("ERROR: wrong file extension (.fdf expected)", 2);
		exit(1);
	}
}

void	remove_gnl_eol(char *line)
{
	while (*line != '\0')
	{
		if (*line == '\n')
		{
			*line = '\0';
			return ;
		}
		line++;
	}
}

static void	group_points_line(t_list *list, t_map *map)
{
	t_list			*next;
	unsigned int	i;

	if (map->nb_c == 0)
		parsing_error(list, NULL, NULL, "ERROR: map format is not valid");
	map->points = (t_point3d **)malloc(map->nb_l * sizeof(t_point3d *));
	if (!map->points)
		parsing_error(list, NULL, NULL, "ERROR: malloc failed");
	i = 0;
	while (list)
	{
		next = list->next;
		map->points[i] = (t_point3d *)list->content;
		free(list);
		list = next;
		i++;
	}
}

static t_point3d	*make_points_line(char **split, t_map *map)
{
	unsigned int	i;
	t_point3d		*points_line;

	i = 0;
	while (split[i] != NULL)
		i++;
	if (i == 0)
		return (NULL);
	if (map->nb_l++ == 0)
		map->nb_c = i;
	else if (map->nb_c != i)
		return (NULL);
	points_line = (t_point3d *)malloc(map->nb_c * sizeof(t_point3d));
	if (!points_line)
		return (NULL);
	if (!fill_points_line(points_line, split, map->nb_l - 1, map))
	{
		free(points_line);
		return (NULL);
	}
	return (points_line);
}

void	parse_file_content(int fd, t_list *begin, t_list *list, t_map *map)
{
	char				*line;
	char				**split;
	t_point3d			*points_line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		remove_gnl_eol(line);
		split = ft_split(line, WHITE_SPACES);
		if (!split)
			parsing_error(begin->next, line, NULL, NULL);
		free(line);
		points_line = make_points_line(split, map);
		if (!points_line)
			parsing_error(begin->next, NULL, split, NULL);
		ft_split_free(split);
		list->next = ft_lstnew(points_line);
		if (!list->next)
			parsing_error(begin->next, points_line, NULL, NULL);
		list = list->next;
	}
	group_points_line(begin->next, map);
}
