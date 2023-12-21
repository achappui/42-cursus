/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:41:18 by achappui          #+#    #+#             */
/*   Updated: 2023/12/21 23:33:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_push_swap *ps, char which)
{
	if (which == A && ps->b.size > 0)
	{
		ps->a.top = (ps->a.top + ps->a.mem_size - 1) % ps->a.mem_size;
		ps->a.stack[ps->a.top] = ps->b.stack[ps->b.top];
		ps->b.top = (ps->b.top + 1) % ps->b.mem_size;
		ps->b.size--;
		ps->a.size++;
	}
	else if (which == B && ps->a.size > 0)
	{
		ps->b.top = (ps->b.top + ps->b.mem_size - 1) % ps->b.mem_size;
		ps->b.stack[ps->b.top] = ps->a.stack[ps->a.top];
		ps->a.top = (ps->a.top + 1) % ps->a.mem_size;
		ps->a.size--;
		ps->b.size++;
	}
}

void	swap(t_push_swap *ps, char which)
{
	int		tmp;

	if (which != B && ps->a.size > 1)
	{
		tmp = ps->a.stack[ps->a.top];
		ps->a.stack[ps->a.top] = ps->a.stack[(ps->a.top + 1) % ps->a.mem_size];
		ps->a.stack[(ps->a.top + 1) % ps->a.mem_size] = tmp;
	}
	if (which != A && ps->b.size > 1)
	{
		tmp = ps->b.stack[ps->b.top];
		ps->b.stack[ps->b.top] = ps->b.stack[(ps->b.top + 1) % ps->b.mem_size];
		ps->b.stack[(ps->b.top + 1) % ps->b.mem_size] = tmp;
	}
}

void	rotate(t_push_swap *ps, char which)
{
	if (which != B && ps->a.size > 1)
	{
		ps->a.stack[(ps->a.top + ps->a.size) % ps->a.mem_size] = \
		ps->a.stack[ps->a.top];
		ps->a.top = (ps->a.top + 1) % ps->a.mem_size;
	}
	if (which != A && ps->b.size > 1)
	{
		ps->b.stack[(ps->b.top + ps->b.size) % ps->b.mem_size] = \
		ps->b.stack[ps->b.top];
		ps->b.top = (ps->b.top + 1) % ps->b.mem_size;
	}
}

void	reverse_rotate(t_push_swap *ps, char which)
{
	if (which != B && ps->a.size > 1)
	{
		ps->a.stack[(ps->a.top + ps->a.mem_size - 1) % ps->a.mem_size] = \
		ps->a.stack[(ps->a.top + ps->a.size - 1) % ps->a.mem_size];
		ps->a.top = (ps->a.top + ps->a.mem_size - 1) % ps->a.mem_size;
	}
	if (which != A && ps->b.size > 1)
	{
		ps->b.stack[(ps->b.top + ps->b.mem_size - 1) % ps->b.mem_size] = \
		ps->b.stack[(ps->b.top + ps->b.size - 1) % ps->b.mem_size];
		ps->b.top = (ps->b.top + ps->b.mem_size - 1) % ps->b.mem_size;
	}
}
