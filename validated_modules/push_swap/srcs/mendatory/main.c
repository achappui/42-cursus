/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:21:23 by achappui          #+#    #+#             */
/*   Updated: 2024/01/17 15:37:37 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		return (0);
	input_handler(&ps, argc, argv);
	if (!ps.a.size)
	{
		free_stacks(&ps);
		return (0);
	}
	init_instructions_list(&ps);
	if (!already_sorted(&ps.a))
	{
		if (ps.a.size == 2)
			swap(&ps, A);
		else if (ps.a.size == 3)
			sort_only_three_a(&ps);
		else
			sorting_algo(&ps);
	}
	print_instructions(&ps);
	free_stacks(&ps);
	free_instructions_list(&ps);
	return (0);
}
