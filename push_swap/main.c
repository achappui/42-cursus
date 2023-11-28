/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:21:23 by achappui          #+#    #+#             */
/*   Updated: 2023/11/28 13:59:27 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(t_stacks *s)
{
	if (s->stack_a)
		free(s->stack_a);
	if (s->stack_b)
		free(s->stack_b);
	exit(write(2, "Error\n", 6));
}

void	init_stacks_infos(t_stacks *s)
{
	s->stack_a = NULL;
	s->size_a = 0;
	s->top_a = 0;
	s->stack_b = NULL;
	s->size_b = 0;
	s->top_b = 0;
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc <= 1)
		return (0);
	init_stacks_infos(&s);
	if (argc == 2)
		if (!split_format_input(&s, argv[1]))
			error_handler(&s);
	else
		if (!format_input(&s, argc - 1, argv + 1))
			error_handler(&s);
	choose_best_algorithm(&s);
	free(s.stack_a);
	free(s.stack_b);
	return (0);
}