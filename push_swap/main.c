/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:21:23 by achappui          #+#    #+#             */
/*   Updated: 2023/12/01 11:06:28 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

void	error_handler(t_stacks *s)
{
	if (s->stack_a)
		free(s->stack_a);
	if (s->stack_b)
		free(s->stack_b);
	write(2, "Error\n", 6);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	//printf("argc: %d\n", argc);
	if (argc-- <= 1)
		return (0);
	if (!init_inputs(&s, argc * !(argc), argv + 1, (argc == 1)))
		error_handler(&s);
	//choose best algo
	
	free(s.stack_a);
	free(s.stack_b);
	return (0);
}