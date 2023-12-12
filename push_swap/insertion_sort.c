/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:54:13 by achappui          #+#    #+#             */
/*   Updated: 2023/12/07 15:59:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_push_swap *ps, unsigned int nb_of_elems)
{
	unsigned int	count;
	unsigned int	i;
	size_t			instruction_counter;

	instruction_counter = 0; //pour les tests
	count = 1;
	while (count < nb_of_elems)
	{
		push(ps, B);
		instruction_counter++;
		i = 0;
		while (i < count)
		{
			reverse_rotate(ps, A);
			instruction_counter++;
			if (ps->b.stack[ps->b.top] < ps->a.stack[ps->a.top])
				i++;
			else
			{
				rotate(ps, A);
				instruction_counter++;
				break ;
			}
		}
		push(ps, A);
		instruction_counter++;
		rotate(ps, A);
		instruction_counter++;
		count++;
		while (i > 0)
		{
			rotate(ps, A);
			instruction_counter++;
			i--;
		}
	}
	printf("NUMBER OF INSTRUCTIONS: %lu\n", instruction_counter);
}