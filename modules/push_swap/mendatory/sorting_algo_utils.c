/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_insertion_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:34:18 by marvin            #+#    #+#             */
/*   Updated: 2023/12/15 22:34:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	sort_only_three_a(t_push_swap *ps)
{
	size_t	instruction_counter;
	int	a;
	int	b;
	int	c;

	instruction_counter = 0;
	a = ps->a.stack[ps->a.top];
	b = ps->a.stack[(ps->a.top + 1) % ps->a.mem_size];
	c = ps->a.stack[(ps->a.top + 2) % ps->a.mem_size];
	if (b < c && a > c)
	{
		rotate(ps, A);
		instruction_counter++;
	}
	else if (c < a && b > a)
	{
		reverse_rotate(ps, A);
		instruction_counter++;
	}
	else if (a > b && b > c)
	{
		swap(ps, A);
		instruction_counter++;
		reverse_rotate(ps, A);
		instruction_counter++;
	}
	else if (a < c && b > c)
	{
		swap(ps, A);
		instruction_counter++;
		rotate(ps, A);
		instruction_counter++;
	}
	else if (b < a && c > a)
	{
		swap(ps, A);
		instruction_counter++;
	}
	return (instruction_counter);
}

void	replace_by_index(t_push_swap *ps)
{
	int				*stack_copy;
	unsigned int	i;
	unsigned int	j;

	stack_copy = (int *)malloc(ps->a.size * sizeof(int));
	if (!stack_copy)
		error_handler(ps);
	i = 0;
	while (i < ps->a.size)
	{
		stack_copy[i] = ps->a.stack[i];
		i++;
	}
	if (!radix_sort(stack_copy, ps->a.size))
		error_handler(ps);
	i = 0;
	while (i < ps->a.size)
	{
		j = 0;
		while (stack_copy[j] != ps->a.stack[i])
			j++;
		ps->a.stack[i] = j;
		i++;
	}
	free(stack_copy);
}

size_t	midpoint_chunker(t_push_swap *ps)
{
	unsigned int	pivot;
	size_t	instruction_counter;

	instruction_counter = 0;
	pivot = ps->a.size;
	while (ps->a.size > 3)
	{
		if (ps->a.size <= pivot)
			pivot = pivot / 2;
		if ((unsigned int)ps->a.stack[ps->a.top] >= pivot)
		{
			push(ps, B);
			instruction_counter++;
		}
		else
		{
			rotate(ps, A);
			instruction_counter++;
		}
	}
	return (instruction_counter);
}
