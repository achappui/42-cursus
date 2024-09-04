/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:10:56 by achappui          #+#    #+#             */
/*   Updated: 2023/12/03 17:10:56 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static char	is_b_empty_and_a_sorted(t_push_swap *ps)
{
	unsigned int	i;
	unsigned int	next;
	unsigned int	top;

	if (ps->b.size != 0)
		return (0);
	top = ps->a.top;
	i = 0;
	while (i < ps->a.size - 1)
	{
		next = (top + 1) % ps->a.mem_size;
		if (ps->a.stack[top] > ps->a.stack[next])
			return (0);
		top = next;
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

	if (argc < 2)
		return (0);
	init_stack(&ps.a);
	init_stack(&ps.b);
	input_handler(&ps, argc, argv);
	if (!ps.a.size)
	{
		free_stacks(&ps);
		return (0);
	}
	run_steps(&ps);
	if (is_b_empty_and_a_sorted(&ps))
	{
		if (write(1, "OK\n", 3) <= 0)
			error_handler(&ps);
	}
	else
	{
		if (write(1, "KO\n", 3) <= 0)
			error_handler(&ps);
	}
	free_stacks(&ps);
	return (0);
}
