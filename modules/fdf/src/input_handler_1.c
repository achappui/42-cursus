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

static void	init_input(t_fdfinput *inputs)
{
	inputs->col_len = 0;
	inputs->line_len = 0;
	inputs->map = NULL;
}

static void	check_arguments(int argc, char *argv[])
{
	size_t	len;

	if (argc < 2 || argc > 2)
	{
		ft_putendl_fd("ERROR: You must enter exactly one map.", 2);
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (len < 4 || !(argv[1][len - 1] == 'f' && argv[1][len - 2] == 'd' && \
					argv[1][len - 3] == 'f' && argv[1][len - 4] == '.'))
	{
		ft_putendl_fd("ERROR: Wrong file extension. (.fdf expected)", 2);
		exit(1);
	}
}

void	free_inputs(t_fdfinput *inputs)
{
	unsigned int	i;

	i = 0;
	while (i < inputs->col_len)
	{
		free(inputs->map[i]);
		i++;
	}
	if (inputs->map)
		free(inputs->map);
}

void	error_handler(t_list *list, void *to_free, char **split_to_free) //amelio gnl
{
	ft_lstclear(&list, &free);
	if (to_free)
		free(to_free);
	if (split_to_free)
		ft_split_free(split_to_free);
	ft_putendl_fd("ERROR (malloc failed or map format is not valid)", 2);
	exit(1);
}

void	input_handler(int argc, char *argv[], t_fdfinput *inputs)
{
	t_list	parsing_list;
	int		fd;

	parsing_list.content = NULL;
	parsing_list.next = NULL;
	init_input(inputs);
	check_arguments(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_putendl_fd("ERROR: could not open the file.", 2);
		exit(1);
	}
	parse_file_content(fd, &parsing_list, &parsing_list, inputs);
	if (close(fd) == -1)
	{
		free_inputs(inputs);
		ft_putendl_fd("ERROR: could not close the file.", 2);
		exit(1);
	}
}