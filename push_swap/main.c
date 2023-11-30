/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:21:23 by achappui          #+#    #+#             */
/*   Updated: 2023/11/30 11:49:49 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_intlist(t_intlist *lst)
{
	t_intlist *next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

void	error_handler(t_stacks *s)
{
	free_intlist(s->stack_a);
	free_intlist(s->stack_b);
	write(2, "Error\n", 6);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	s.stack_a = NULL;
	s.stack_b = NULL;
	printf("argc: %d\n", argc);
	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		if (!receive_inputs_b(&s, argv[1]))
			error_handler(&s);
	}
	else if (argc > 2)
	{
		if (!receive_inputs_a(&s, argc - 1, argv + 1))
			error_handler(&s);
	}
	//printf("STACK A %s STACK B %s\n", s.stack_a, s.stack_b);
	// int i = 0;
	// while (s.stack_a)
	// {
	// 	printf("%i ", s.stack_a->elem);
	// 	s.stack_a = s.stack_a->next;
	// }

	//printf("\nyo");
	bubble_sort(&s);
	int i = 0;
	while (s.stack_a)
	{
		printf("%i ", s.stack_a->elem);
		s.stack_a = s.stack_a->next;
	}
	//choose_best_algorithm(&s);
	//free_intlist(s.stack_a);
	return (0);
}