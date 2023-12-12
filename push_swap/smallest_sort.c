/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:50:52 by marvin            #+#    #+#             */
/*   Updated: 2023/12/08 14:50:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_smallest_index(t_stack *s, unsigned int top)
{
	unsigned int	smallest_index;
	int				smallest;
	unsigned int	i;

	smallest = s->stack[top];
	smallest_index = 0;
	i = 0;
	while (i < s->size)
	{
		if (s->stack[top] < smallest)
		{
			smallest = s->stack[top];
			smallest_index = i;
		}
		top = (top + 1) % s->mem_size;
		i++;
	}
	return (smallest_index);
}

void	smallest_sort(t_push_swap *ps)
{
	unsigned int	smallest_index;
	size_t			instruction_counter;

	while (ps->a.size > 0)
	{
		smallest_index = get_smallest_index(&ps->a, ps->a.top);
		printf("smallest index: %u\n", smallest_index);
		while (smallest_index-- > 0)
		{
			rotate(ps, A);
			instruction_counter++;
		}
		push(ps, B);
		instruction_counter++;
	}
	while (ps->b.size > 0)
	{
		push(ps, A);
		instruction_counter++;
	}
	printf("NUMBER OF INSTRUCTIONS: %lu\n", instruction_counter);
}