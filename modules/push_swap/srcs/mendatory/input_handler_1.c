/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:59 by achappui          #+#    #+#             */
/*   Updated: 2024/01/13 20:03:03 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split_list(t_list *list)
{
	unsigned int	i;
	char			**split;
	t_list			*next;

	while (list)
	{
		next = list->next;
		if (list->content)
		{
			i = 0;
			split = (char **)list->content;
			while (split[i] != NULL)
				free(split[i++]);
			free(split);
		}
		free(list);
		list = next;
	}
}

void	input_error_handler(t_push_swap *ps, t_list *list)
{
	if (ps)
	{
		if (ps->a.stack)
			free(ps->a.stack);
		if (ps->b.stack)
			free(ps->b.stack);
	}
	if (list)
		free_split_list(list);
	write(2, "Error\n", 6);
	exit(1);
}

static int	get_nb_of_elem(t_list *list)
{
	int		arg_nb;
	int		i;
	char	**split;

	arg_nb = 0;
	list = list->next;
	while (list)
	{
		i = 0;
		split = (char **)list->content;
		while (split[i] != NULL)
		{
			arg_nb++;
			i++;
		}
		list = list->next;
	}
	return (arg_nb);
}

static void	get_split_list(t_list *list, int argc, char *argv[])
{
	int		i;
	char	**split;
	t_list	*begin;

	begin = list;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], WHITE_SPACES);
		if (!split)
			input_error_handler(NULL, begin->next);
		list->next = ft_lstnew(split);
		if (!list->next)
		{
			i = 0;
			while (split[i] != NULL)
				free(split[i++]);
			free(split);
			input_error_handler(NULL, begin->next);
		}
		list = list->next;
		i++;
	}
}

void	input_handler(t_push_swap *ps, int argc, char *argv[])
{
	t_list	input_list;
	int		nb_of_elem;

	input_list.content = NULL;
	input_list.next = NULL;
	nb_of_elem = 0;
	get_split_list(&input_list, argc, argv);
	nb_of_elem = get_nb_of_elem(&input_list);
	ps->a.size = nb_of_elem;
	ps->a.mem_size = nb_of_elem + 1;
	ps->b.mem_size = nb_of_elem + 1;
	ps->a.stack = (int *)malloc(ps->a.mem_size * sizeof(int));
	if (!ps->a.stack)
		input_error_handler(ps, input_list.next);
	ps->b.stack = (int *)malloc(ps->b.mem_size * sizeof(int));
	if (!ps->b.stack)
		input_error_handler(ps, input_list.next);
	fill_stack_a(ps, &input_list);
	free_split_list(input_list.next);
}
