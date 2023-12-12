/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:32:32 by achappui          #+#    #+#             */
/*   Updated: 2023/12/12 09:41:58 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_push_swap *ps)
{
	unsigned int	i;
	size_t			instruction_counter;

	while (ps->a.size)
	{
		i = 0;
		while (i < ps->a.size - 1)
		{
			if (ps->a.stack[ps->a.top] < ps->a.stack[(ps->a.top + 1) % ps->a.mem_size])
			{
				swap(ps, A);
				rotate(ps, A);
				instruction_counter++;
			}
			else
			{
				rotate(ps, A);
				instruction_counter++;
			}
			i++;
		}
		push(ps, B);
	}
	while (ps->b.size)
	{
		push(ps, A);
		instruction_counter++;
	}
	printf("NUMBER OF INSTRUCTIONS: %lu\n", instruction_counter);
}