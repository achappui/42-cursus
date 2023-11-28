/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:41:18 by achappui          #+#    #+#             */
/*   Updated: 2023/11/28 15:10:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stacks *s, char which)
{
	int				tmp1;
	int				tmp2;
	unsigned int	i;

	if (which == 'A' && s->size_a > 0)
	{
		s
		s->size_a--;
	}
	else if (which == 'B' && s->size_b > 0)
	{
		
		s->size_b--;
	}
	while (i < s->size_a)
	{
		tmp2 = s->size_a[i];
		s->size_a[i] = tmp1;
		i++;
	}
}

void	swap(t_stacks *s, char which)
{
	int	tmp;

	if (which != 'B' && s->size_a > 1)
	{
		tmp = s->stack_a[s->top_a];
		s->stack_a[s->top_a] = s->stack_a[(s->top_a + s->size_a - 1) % s->size_a];
		s->stack_a[(s->top_a + s->size_a - 1) % s->size_a] = tmp;
	}
	if (which != 'A' && s->size_b > 1)
	{
		tmp = s->stack_b[s->top_b];
		s->stack_b[s->top_b] = s->stack_b[(s->top_b + s->size_b - 1) % s->size_b];
		s->stack_b[(s->top_b + s->size_b - 1) % s->size_b] = tmp;
	}
}

void	rotate(t_stacks *s, char which)
{
	if (which != 'B')
		s->top_a = (s->top_a + s->size_a - 1) % s->size_a;
	if (which != 'A')
		s->top_b = (s->top_b + s->size_b - 1) % s->size_b;
}

void	reverse_rotate(t_stacks *s, char which)
{
	if (which != 'B')
		s->top_a = (s->top_a + s->size_a + 1) % s->size_a;
	if (which != 'A')
		s->top_b = (s->top_b + s->size_b + 1) % s->size_b;
}