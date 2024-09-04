/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:34:51 by achappui          #+#    #+#             */
/*   Updated: 2024/01/17 15:39:41 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_instructions_list(t_push_swap *ps)
{
	t_ins_block	*next;

	ps->first = ps->first->next;
	while (ps->first)
	{
		next = ps->first->next;
		free(ps->first);
		ps->first = next;
	}
}

char	already_sorted(t_stack *s)
{
	unsigned int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (s->stack[i] > s->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	init_instructions_list(t_push_swap	*ps)
{
	ps->ins_list.used_space = INS_BUFFER_SIZE;
	ps->ins_list.next = NULL;
	ps->first = &ps->ins_list;
	ps->current = &ps->ins_list;
}

void	print_instructions(t_push_swap	*ps)
{
	ps->current = ps->first->next;
	while (ps->current)
	{
		if (write(1, ps->current->buffer, ps->current->used_space) == -1)
			error_handler(ps);
		ps->current = ps->current->next;
	}
}

void	error_handler(t_push_swap *ps)
{
	if (ps->first->next)
		free_instructions_list(ps);
	free_stacks(ps);
	write(2, "Error\n", 6);
	exit(1);
}
