/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:42 by achappui          #+#    #+#             */
/*   Updated: 2023/11/30 16:28:10 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stacks *s)
{
	//unsigned int	i;
	unsigned int	size;

	size = s->len_a;
	reverse_rotate(s, RRA);

	// while (size > 1)
	// {
	// 	i = 0;
	// 	while (i < size)
	// 	{
	// 		if (s->stack_a->elem > s->stack_a->next->elem)
	// 			swap(s, S_A);
	// 		rotate(s, R_A);
	// 		i++;
	// 	}
	// 	size--;
	// }
	//swap(s, S_A);
}