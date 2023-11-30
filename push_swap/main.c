/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:21:23 by achappui          #+#    #+#             */
/*   Updated: 2023/11/30 18:49:18 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(t_stacks *s)
{
	if (s->ptr_a)
		free(s->ptr_a);
	if (s->ptr_b)
		free(s->ptr_b);
	write(2, "Error\n", 6);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	//printf("argc: %d\n", argc);
	if (argc <= 1)
		return (0);
	if (!init_inputs(&s, --argc * !(argc), argv + 1, (argc == 1)))
		error_handler(&s);
	//choose best algo
	free(s.ptr_a);
	free(s.ptr_b);
	return (0);
}