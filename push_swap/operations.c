/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:41:18 by achappui          #+#    #+#             */
/*   Updated: 2023/11/28 19:22:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stacks *s, const char *txt)
{
	t_intlist	*tmp;

	if (txt[1] == 'a' && s->len_b > 0)
	{
		tmp = s->stack_a->next;
		s->stack_a = s->stack_b;
		s->stack_a->next = tmp;
		s->stack_b = s->stack_b->next;
		s->len_a++;
		s->len_b--;
	}
	else if (txt[1] == 'b' && s->len_a > 0)
	{
		tmp = s->stack_b->next;
		s->stack_b = s->stack_a;
		s->stack_b->next = tmp;
		s->stack_a = s->stack_a->next;
		s->len_b++;
		s->len_a--;
	}
	if (write(2, txt, 2) <= 0)
		error_handler(s);
}

void	swap(t_stacks *s, const char *txt)
{
	t_intlist	*tmp;

	if (txt[1] != 'b' && s->len_a > 1)
	{
		tmp = s->stack_a;
		s->stack_a = s->stack_a->next;
		tmp->next = s->stack_a->next;
		s->stack_a->next = tmp;
	}
	if (txt[1] != 'a' && s->len_b > 1)
	{
		tmp = s->stack_b;
		s->stack_b = s->stack_b->next;
		tmp->next = s->stack_b->next;
		s->stack_b->next = tmp;
	}
	if (write(2, txt, 2) <= 0)
		error_handler(s);
}

void	rotate(t_stacks *s, const char *txt)
{
	t_intlist	*last;

	if (txt[1] != 'b' && s->len_a > 1)
	{
		last = s->stack_a;
		while (last->next)
			last = last->next;
		last->next = s->stack_a;
		s->stack_a = s->stack_a->next;
		last->next->next = NULL;
	}
	if (txt[1] != 'a' && s->len_b > 1)
	{
		last = s->stack_b;
		while (last->next)
			last = last->next;
		last->next = s->stack_b;
		s->stack_b = s->stack_b->next;
		last->next->next = NULL;
	}
	if (write(2, txt, 2) <= 0)
		error_handler(s);
}

void	reverse_rotate(t_stacks *s, const char *txt)
{
	t_intlist	**last;

	if (txt[2] != 'b' && s->len_a > 1)
	{
		*last = s->stack_a;
		while ((*last)->next)
			last = &(*last)->next;
		(*last)->next = s->stack_a;
		s->stack_a = *last;
		*last = NULL;
	}
	if (txt[2] != 'a' && s->len_b > 1)
	{
		*last = s->stack_b;
		while ((*last)->next)
			last = &(*last)->next;
		(*last)->next = s->stack_b;
		s->stack_b = *last;
		*last = NULL;
	}
	if (write(2, txt, 3) <= 0)
		error_handler(s);
}