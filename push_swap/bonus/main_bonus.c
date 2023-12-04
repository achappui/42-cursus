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

static void	free_all(t_checker *c)
{
	t_list	*next;

	if (c->a.stack)
		free(c->a.stack);
	if (c->b.stack)
		free(c->b.stack);
	while (c->steps)
	{
		next = c->steps->next;
		if (c->steps->content)
			free(c->steps->content);
		free(c->steps);
		c->steps = next;
	}
}

static char	is_b_empty_and_a_sorted(t_checker *c)
{
	unsigned int	size;
	unsigned int	top;

	if (c->b.size != 0)
		return (0);
	size = c->a.size;
	top = c->a.top;
	while (size > 1)
	{
		if (c->a.stack[top] >= c->a.stack[(top + 1) % c->a.mem_size])
			return (0);
		top = (top + 1) % c->a.mem_size;
		size--;
	}
	return (1);
}

void	error_handler(t_checker *c)
{
	free_all(c);
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

// void	print_stack_infos(t_stack *s)
// {
// 	printf("mem_size: %u\n", s->mem_size);
// 	printf("size: %u\n", s->size);
// 	printf("stack: %p\n", s->stack);
// 	printf("top: %u\n", s->top);
// }

int	main(int argc, char **argv)
{
	t_checker	c;

	if (argc < 2)
		return (0);
	--argc;
	++argv;
	init_stack(&c.a);
	init_stack(&c.b);
	c.steps = NULL;
	build_stack_a_and_b(&c, argc, argv, (argc == 1));
	check_and_get_steps(&c);
	run_steps(&c);
	if (is_b_empty_and_a_sorted(&c))
	{
		if (write(1, "OK\n", 3) <= 0)
			error_handler(&c);
	}
	else
	{
		if (write(1, "KO\n", 3) <= 0)
			error_handler(&c);
	}
	free_all(&c);
	return (0);
}