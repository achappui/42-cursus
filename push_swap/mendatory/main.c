/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:21:23 by achappui          #+#    #+#             */
/*   Updated: 2023/12/04 16:48:23 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->mem_size = 0;
	s->stack = NULL;
	s->size = 0;
	s->top = 0;
}

void	free_all(t_push_swap *ps)
{
	if (ps->a.stack)
		free(ps->a.stack);
	if (ps->b.stack)
		free(ps->b.stack);
}

void	error_handler(t_push_swap *ps)
{
	free_all(ps);
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

void	print_stack_infos(t_stack *s)
{
	printf("mem_size: %u\n", s->mem_size);
	printf("size: %u\n", s->size);
	printf("stack: %p\n", s->stack);
	printf("top: %u\n", s->top);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		return (0);
	init_stack(&ps.a);
	init_stack(&ps.b);
	--argc;
	++argv;
	build_stack_a_and_b(&ps, argc, argv, (argc == 1));

	free_all(&ps);
	return (0);
}