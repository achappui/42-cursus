/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:51:34 by achappui          #+#    #+#             */
/*   Updated: 2023/12/21 23:31:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_best_move(unsigned int *arr)
{
	arr[MIN_OP] = arr[RA] + arr[RRB];
	arr[WHICH_MOVE] = 1;
	if (arr[RRA] + arr[RB] < arr[MIN_OP])
	{
		arr[MIN_OP] = arr[RRA] + arr[RB];
		arr[WHICH_MOVE] = 2;
	}
	if ((arr[RA] >= arr[RB] && arr[RA] < arr[MIN_OP]) || \
		(arr[RB] >= arr[RA] && arr[RB] < arr[MIN_OP]))
	{
		if (arr[RB] > arr[RA])
			arr[MIN_OP] = arr[RB];
		else
			arr[MIN_OP] = arr[RA];
		arr[WHICH_MOVE] = 3;
	}
	if ((arr[RRA] >= arr[RRB] && arr[RRA] < arr[MIN_OP]) || \
		(arr[RRB] >= arr[RRA] && arr[RRB] < arr[MIN_OP]))
	{
		if (arr[RRB] > arr[RRA])
			arr[MIN_OP] = arr[RRB];
		else
			arr[MIN_OP] = arr[RRA];
		arr[WHICH_MOVE] = 4;
	}
}

static void	pepare_move(unsigned int *arr)
{
	if (arr[WHICH_MOVE] == 1)
	{
		arr[RB] = 0;
		arr[RRA] = 0;
	}
	else if (arr[WHICH_MOVE] == 2)
	{
		arr[RA] = 0;
		arr[RRB] = 0;
	}
	else if (arr[WHICH_MOVE] == 3)
	{
		arr[RRA] = 0;
		arr[RRB] = 0;
	}
	else if (arr[WHICH_MOVE] == 4)
	{
		arr[RA] = 0;
		arr[RB] = 0;
	}
}

static void	execute_move(t_push_swap *ps, unsigned int *cmd_arr)
{
	while (cmd_arr[RA] && cmd_arr[RB] && cmd_arr[RA]-- && cmd_arr[RB]--)
		rotate(ps, BOTH);
	while (cmd_arr[RA] && cmd_arr[RA]--)
		rotate(ps, A);
	while (cmd_arr[RB] && cmd_arr[RB]--)
		rotate(ps, B);
	while (cmd_arr[RRA] && cmd_arr[RRB] && cmd_arr[RRA]-- && cmd_arr[RRB]--)
		reverse_rotate(ps, BOTH);
	while (cmd_arr[RRA] && cmd_arr[RRA]--)
		reverse_rotate(ps, A);
	while (cmd_arr[RRB] && cmd_arr[RRB]--)
		reverse_rotate(ps, B);
}

static void	calcul_elem_moves(t_push_swap *ps, unsigned int *arr, \
								unsigned int i, int elem)
{
	unsigned int	j;
	unsigned int	current;
	unsigned int	prev;

	j = 0;
	current = ps->a.top;
	while (1)
	{
		prev = (ps->a.top + ps->a.size - 1 - j) % ps->a.mem_size;
		if (ps->a.stack[prev] > ps->a.stack[current])
		{
			if (elem > ps->a.stack[prev] || elem < ps->a.stack[current])
				break ;
		}
		else if (ps->a.stack[prev] < elem && ps->a.stack[current] > elem)
			break ;
		current = prev;
		j++;
	}
	arr[RB] = i;
	arr[RRB] = ps->b.size - i;
	arr[RA] = ps->a.size - j;
	arr[RRA] = j;
}

void	sorting_algo(t_push_swap *ps)
{
	unsigned int	i;
	unsigned int	top;
	unsigned int	opti_elem[6];
	unsigned int	tmp_elem[6];

	midpoint_chunker(ps);
	while (ps->b.size > 0)
	{
		i = 0;
		opti_elem[MIN_OP] = -1;
		top = ps->b.top;
		while (i < ps->b.size)
		{
			calcul_elem_moves(ps, tmp_elem, i++, ps->b.stack[top]);
			choose_best_move(tmp_elem);
			if (tmp_elem[MIN_OP] < opti_elem[MIN_OP])
				ft_memcpy(opti_elem, tmp_elem, 6 * sizeof(int));
			top = (top + 1) % ps->b.mem_size;
		}
		pepare_move(opti_elem);
		execute_move(ps, opti_elem);
		push(ps, A);
	}
	rotate_to_sorted(ps);
}
