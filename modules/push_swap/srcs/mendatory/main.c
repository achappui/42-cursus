/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:21:23 by achappui          #+#    #+#             */
/*   Updated: 2023/12/21 23:27:27 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *s)
{
	s->mem_size = 0;
	s->stack = NULL;
	s->size = 0;
	s->top = 0;
}

static void	free_stacks(t_push_swap *ps)
{
	if (ps->a.stack)
		free(ps->a.stack);
	if (ps->b.stack)
		free(ps->b.stack);
}

static char	already_sorted(t_stack *s)
{
	unsigned int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (s->stack[i] > s->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	error_handler(t_push_swap *ps)
{
	free_stacks(ps);
	write(2, "Error\n", 6);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc-- < 2)
		return (0);
	init_stack(&ps.a);
	init_stack(&ps.b);
	build_stack_a_and_b(&ps, argc, argv + 1, (argc == 1));
	if (!ps.a.size)
		return (0);
	if (!already_sorted(&ps.a))
	{
		if (ps.a.size == 2)
			swap(&ps, A);
		else if (ps.a.size == 3)
			sort_only_three_a(&ps);
		else
			sorting_algo(&ps);
	}
	free_stacks(&ps);
	return (0);
}
