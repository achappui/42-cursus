/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:41:18 by achappui          #+#    #+#             */
/*   Updated: 2023/11/30 19:31:56 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stacks *s, const char *txt)
{
	t_intlist	*tmp;

	if (txt[1] == 'a' && s->h_a != s->t_a)
	{

	}
	else if (txt[1] == 'b' && s->len_a > 0)
	{

	}
	if (write(2, txt, 3) <= 0)
		error_handler(s);
}

void	swap(t_stacks *s, const char *txt)
{
	t_intlist	*tmp;

	if (txt[1] != 'b' && s->len_a > 1)
	{

	}
	if (txt[1] != 'a' && s->len_b > 1)
	{

	}
	if (write(2, txt, 3) <= 0)
		error_handler(s);
}

void	rotate(t_stacks *s, const char *txt)
{
	t_intlist	*last;

	if (txt[1] != 'b' && s->len_a > 1)
	{

	}
	if (txt[1] != 'a' && s->len_b > 1)
	{

	}
	if (write(2, txt, 3) <= 0)
		error_handler(s);
}

void	reverse_rotate(t_stacks *s, const char *txt)
{
	t_intlist	**last;

	if (txt[2] != 'b' && s->len_a > 1)
	{

	}
	if (txt[2] != 'a' && s->len_b > 1)
	{

	}
	if (write(2, txt, 4) <= 0)
		error_handler(s);
}