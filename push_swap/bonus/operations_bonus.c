/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:41:18 by achappui          #+#    #+#             */
/*   Updated: 2023/12/04 16:51:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_checker *c, char which)
{
	if (which == A && c->b.size > 0)
	{
		c->a.top = (c->a.top + c->a.mem_size - 1) % c->a.mem_size;
		c->a.stack[c->a.top] = c->b.stack[c->b.top];
		c->b.top = (c->b.top + 1) % c->b.mem_size;
		c->b.size--;
		c->a.size++;
	}
	else if (which == B && c->a.size > 0)
	{
		c->b.top = (c->b.top + c->b.mem_size - 1) % c->b.mem_size;
		c->b.stack[c->b.top] = c->a.stack[c->a.top];
		c->a.top = (c->a.top + 1) % c->a.mem_size;
		c->a.size--;
		c->b.size++;
	}
}

void	swap(t_checker *c, char which)
{
	int		tmp;

	if (which != B && c->a.size > 1)
	{
		tmp = c->a.stack[c->a.top];
		c->a.stack[c->a.top] = c->a.stack[(c->a.top + 1) % c->a.mem_size];
		c->a.stack[(c->a.top + 1) % c->a.mem_size] = tmp;
	}
	if (which != A && c->b.size > 1)
	{
		tmp = c->b.stack[c->b.top];
		c->b.stack[c->b.top] = c->b.stack[(c->b.top + 1) % c->b.mem_size];
		c->b.stack[(c->b.top + 1) % c->b.mem_size] = tmp;
	}
}

void	rotate(t_checker *c, char which)
{
	if (which != B && c->a.size > 1)
	{
		c->a.stack[(c->a.top + c->a.size) % c->a.mem_size] = \
		c->a.stack[c->a.top];
		c->a.top = (c->a.top + 1) % c->a.mem_size;
	}
	if (which != A && c->b.size > 1)
	{
		c->b.stack[(c->b.top + c->b.size) % c->b.mem_size] = \
		c->b.stack[c->b.top];
		c->b.top = (c->b.top + 1) % c->b.mem_size;
	}
}

void	reverse_rotate(t_checker *c, char which)
{
	if (which != B && c->a.size > 1)
	{
		c->a.stack[(c->a.top + c->a.mem_size - 1) % c->a.mem_size] = \
		c->a.stack[(c->a.top + c->a.size - 1) % c->a.mem_size];
		c->a.top = (c->a.top + c->a.mem_size - 1) % c->a.mem_size;
	}
	if (which != A && c->b.size > 1)
	{
		c->b.stack[(c->b.top + c->b.mem_size - 1) % c->b.mem_size] = \
		c->b.stack[(c->b.top + c->b.size - 1) % c->b.mem_size];
		c->b.top = (c->b.top + c->b.mem_size - 1) % c->b.mem_size;
	}
}