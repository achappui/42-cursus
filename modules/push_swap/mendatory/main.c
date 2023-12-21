/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:21:23 by achappui          #+#    #+#             */
/*   Updated: 2023/12/21 22:15:12 by achappui         ###   ########.fr       */
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

void	error_handler(t_push_swap *ps)
{
	free_stacks(ps);
	write(2, "Error\n", 6);
	exit(-1);
}

void	print_stack(t_stack *s)
{
	unsigned int	size;
	unsigned int	top;

	size = s->size;
	top = s->top;
	while (size > 0)
	{
		printf("%d ", s->stack[top]);
		top = (top + 1) % s->mem_size;
		size--;
	}
	printf("\n");
}

void	is_stack_sorted(t_push_swap *ps)
{
	unsigned int	i;
	unsigned int	top;

	i = 0;
	top = ps->a.top;
	while (i < ps->a.size - 1)
	{
		if (ps->a.stack[top] > ps->a.stack[(top + 1) % ps->a.mem_size])
		{
			printf("NO\n");
			return ;
		}
		top = (top + 1) % ps->a.mem_size;
		i++;
	}
	//printf("\nYES\n");
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
		// printf("STACK A: ");
		// print_stack(&ps.a);
		// printf("STACK B: ");
		// print_stack(&ps.b);
		// if (ps.a.size <= 5)
		// 	little_sort(&ps);
		// else
		// if (ps.a.size == 2) //est-ce que le cas ou ya que 1 element est checker dans already sorted ?
		// 	swap(&ps, A);
		if (ps.a.size == 2)
			swap(&ps, A);
		else if (ps.a.size == 3)
			sort_only_three_a(&ps);
		else
			sorting_algo(&ps);
		// printf("STACK A: ");
		// print_stack(&ps.a);
		// printf("STACK B: ");
		// print_stack(&ps.b);
		is_stack_sorted(&ps);
	}
	free_stacks(&ps);
	return (0);
}