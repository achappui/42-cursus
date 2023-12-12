/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2023/12/12 09:41:07 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# define WHITE_SPACES " \t\n\v\f\r"

# define A		'a'
# define B		'b'
# define BOTH	'c'

typedef struct	s_stack
{
	int				*stack;
	unsigned int	mem_size;
	unsigned int	top;
	unsigned int	size;
}	t_stack;

typedef struct	s_push_swap
{
	struct s_stack	a;
	struct s_stack	b;
}	t_push_swap;

//algos
void	insertion_sort(t_push_swap *ps, unsigned int nb_of_elems);
void	bubble_sort(t_push_swap *ps);
void	smallest_sort(t_push_swap *ps);

void	build_stack_a_and_b(t_push_swap *ps, unsigned int size, char **args, char split);
void	push(t_push_swap *ps, char which);
void	swap(t_push_swap *ps, char which);
void	rotate(t_push_swap *ps, char which);
void	reverse_rotate(t_push_swap *ps, char which);
void	error_handler(t_push_swap *ps);

#endif