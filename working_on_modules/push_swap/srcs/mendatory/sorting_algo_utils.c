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

void	rotate_to_sorted(t_push_swap *ps)
{
	if ((unsigned int)ps->a.stack[ps->a.top] > (ps->a.size - 1) / 2)
		while (ps->a.stack[ps->a.top] != 0)
			rotate(ps, A);
	else
		while (ps->a.stack[ps->a.top] != 0)
			reverse_rotate(ps, A);
}

void	sort_only_three_a(t_push_swap *ps)
{
	int		a;
	int		b;
	int		c;

	a = ps->a.stack[ps->a.top];
	b = ps->a.stack[(ps->a.top + 1) % ps->a.mem_size];
	c = ps->a.stack[(ps->a.top + 2) % ps->a.mem_size];
	if (b < c && a > c)
		rotate(ps, A);
	else if (c < a && b > a)
		reverse_rotate(ps, A);
	else if (a > b && b > c)
	{
		swap(ps, A);
		reverse_rotate(ps, A);
	}
	else if (a < c && b > c)
	{
		swap(ps, A);
		rotate(ps, A);
	}
	else if (b < a && c > a)
		swap(ps, A);
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

void	midpoint_chunker(t_push_swap *ps)
{
	unsigned int	pivot;

	replace_by_index(ps);
	pivot = ps->a.size;
	while (ps->a.size > 3)
	{
		if (ps->a.size <= pivot)
			pivot = pivot / 2;
		if ((unsigned int)ps->a.stack[ps->a.top] >= pivot)
			push(ps, B);
		else
			rotate(ps, A);
	}
	sort_only_three_a(ps);
}
