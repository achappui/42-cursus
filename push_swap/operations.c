/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:41:18 by achappui          #+#    #+#             */
/*   Updated: 2023/12/05 10:04:34 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_push_swap *ps, char which)
{
	char	txt[3];

	txt[0] = 'p';
	txt[1] = (which == A) * 'a' + (which == B) * 'b';
	txt[2] = '\n';
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
	if (write(2, txt, 3) <= 0)
		error_handler(ps);
}

void	swap(t_push_swap *ps, char which)
{
	int		tmp;
	char	txt[3];

	txt[0] = 's';
	txt[1] = (which == A) * 'a' + (which == B) * 'b' + (which > 'b') * 's';
	txt[2] = '\n';
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
	if (write(2, txt, 3) <= 0)
		error_handler(ps);
}

void	rotate(t_push_swap *ps, char which)
{
	char	txt[3];

	txt[0] = 'r';
	txt[1] = (which == A) * 'a' + (which == B) * 'b' + (which > 'b') * 'r';
	txt[2] = '\n';
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
	if (write(2, txt, 3) <= 0)
		error_handler(ps);
}

void	reverse_rotate(t_push_swap *ps, char which)
{
	char	txt[4];

	txt[0] = 'r';
	txt[1] = 'r';
	txt[2] = (which == A) * 'a' + (which == B) * 'b' + (which > 'b') * 'r';
	txt[3] = '\n';
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
	if (write(2, txt, 4) <= 0)
		error_handler(ps);
}