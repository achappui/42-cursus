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

static void	remove_gnl_eol(char *line)
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

static void	make_map_2darray(t_list *list, t_fdfinput *inputs) //on oublie pas que le premier de list est un noeud local qui ne compte pas dans la vrai liste
{
	t_list			*next;
	unsigned int	i;

	if (inputs->col_len == 0)
		error_handler(list, NULL, NULL);
	inputs->map = (long long **)malloc(inputs->col_len * sizeof(long long *));
	if (!inputs->map)
		error_handler(list, NULL, NULL);
	i = 0;
	while (list)
	{
		next = list->next;
		inputs->map[i] = (long long *)list->content;
		free(list);
		list = next;
		i++;
	}
}

static char	fill_array(long long *array, char **split)
{
	unsigned int	i;
	unsigned int	j;
	long long		valid_z;
	long long		valid_color;

	i = 0;
	valid_color = 0xFFFFFF;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != ',' && split[i][j] != '\0')
			j++;
		if (split[i][j] == ',')
		{
			valid_color = validate_int(split[i] + j + 1);
			split[i][j] = '\0';
		}
		valid_z = validate_int(split[i]);
		if (valid_color == INVALID || valid_z == INVALID)
			return (0);
		array[i] = valid_z << 32 | valid_color;
		i++;
	}
	return (1);
}

static long long	*make_valid_int_array(char **split, t_fdfinput *inputs)
{
	unsigned int	i;
	long long		*array;

	i = 0;
	while (split[i] != NULL)
		i++;
	if (i == 0)
		return (NULL);
	if (inputs->col_len++ == 0)
		inputs->line_len = i;
	else if (inputs->line_len != i)
		return (NULL);
	array = (long long *)malloc(i * sizeof(long long));
	if (!array)
		return (NULL);
	if (!fill_array(array, split))
	{
		free(array);
		return (NULL);
	}
	return (array);
}

void	parse_file_content(int fd, t_list *begin, t_list *list, t_fdfinput *inputs)// balancer un premier element local a une fonction qui se freera tout seul mais qui sert de noeud de dep pour les malloquer
{
	char				*line;
	char				**split;
	long long			*array;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		remove_gnl_eol(line);
		split = ft_split(line, WHITE_SPACES);
		if (!split)
			error_handler(begin->next, line, NULL);
		free(line);
		array = make_valid_int_array(split, inputs);
		if (!array)
			error_handler(begin->next, NULL, split);
		ft_split_free(split);
		list->next = ft_lstnew(array);
		if (!list->next)
			error_handler(begin->next, array, NULL);
		list = list->next;
	}
	make_map_2darray(begin->next, inputs);
}
