/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:41:18 by achappui          #+#    #+#             */
/*   Updated: 2023/12/01 10:55:32 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stacks *s, const char *txt)
{
	if (txt[1] == 'a' && s->size_a > 0)
	{
		s->top_b = (s->top_b + s->buff_size - 1) % s->buff_size;
		s->stack_b[s->top_b] = s->stack_a[s->top_a];
		s->top_a = (s->top_a + 1) % s->buff_size;
		s->size_a--;
		s->size_b++;
	}
	else if (txt[1] == 'b' && s->size_b > 0)
	{
		s->top_b = (s->top_b + s->buff_size - 1) % s->buff_size;
		s->stack_b[s->top_b] = s->stack_a[s->top_a];
		s->top_a = (s->top_a + 1) % s->buff_size;
		s->size_a--;
		s->size_b++;
	}
	if (write(2, txt, 3) <= 0)
		error_handler(s);
}

void	swap(t_stacks *s, const char *txt)
{
	int	tmp;

	if (txt[1] != 'b' && s->size_a > 1)
	{
		tmp = s->stack_a[s->top_a];
		s->stack_a[s->top_a] = s->stack_a[(s->top_a + 1) % s->buff_size];
		s->stack_a[(s->top_a + 1) % s->buff_size] = tmp;
	}
	if (txt[1] != 'a' && s->size_b > 1)
	{
		tmp = s->stack_b[s->top_b];
		s->stack_b[s->top_b] = s->stack_b[(s->top_b + 1) % s->buff_size];
		s->stack_b[(s->top_b + 1) % s->buff_size] = tmp;
	}
	if (write(2, txt, 3) <= 0)
		error_handler(s);
}

void	rotate(t_stacks *s, const char *txt)
{
	if (txt[1] != 'b' && s->size_a > 1)
	{
		s->stack_a[(s->top_a + s->size_a) % s->buff_size] = \
		s->stack_a[s->top_a];
		s->top_a = (s->top_a + 1) % s->buff_size;
	}
	if (txt[1] != 'a' && s->size_b > 1)
	{
		s->stack_b[(s->top_b + s->size_b) % s->buff_size] = \
		s->stack_b[s->top_b];
		s->top_b = (s->top_b + 1) % s->buff_size;
	}
	if (write(2, txt, 3) <= 0)
		error_handler(s);
}

void	reverse_rotate(t_stacks *s, const char *txt)
{
	if (txt[1] != 'b' && s->size_a > 1)
	{
		s->stack_a[(s->top_a + s->buff_size - 1) % s->buff_size] = \
		s->stack_a[(s->top_a + s->size_a - 1) % s->buff_size];
		s->top_a = (s->top_a + s->buff_size - 1) % s->buff_size;
	}
	if (txt[1] != 'a' && s->size_b > 1)
	{
		s->stack_b[(s->top_b + s->buff_size - 1) % s->buff_size] = \
		s->stack_b[(s->top_b + s->size_b - 1) % s->buff_size];
		s->top_b = (s->top_b + s->buff_size - 1) % s->buff_size;
	}
	if (write(2, txt, 4) <= 0)
		error_handler(s);
}