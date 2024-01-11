/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2023/12/21 23:31:25 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../libs/libft/libft.h"

# define WHITE_SPACES	" \t\n\v\f\r"
# define A				'a'
# define B				'b'
# define BOTH			'c'
# define RA				0
# define RRA			1
# define RB				2
# define RRB			3
# define MIN_OP			4
# define WHICH_MOVE		5

typedef struct s_stack
{
	int				*stack;
	unsigned int	mem_size;
	unsigned int	top;
	unsigned int	size;
}	t_stack;

typedef struct s_push_swap
{
	struct s_stack	a;
	struct s_stack	b;
}	t_push_swap;

int		*radix_sort(int arr[], unsigned int size);
void	sort_only_three_a(t_push_swap *ps);
void	replace_by_index(t_push_swap *ps);
void	sorting_algo(t_push_swap *ps);
void	error_handler(t_push_swap *ps);
void	push(t_push_swap *ps, char which);
void	swap(t_push_swap *ps, char which);
void	rotate(t_push_swap *ps, char which);
void	reverse_rotate(t_push_swap *ps, char which);
void	midpoint_chunker(t_push_swap *ps);
void	rotate_to_sorted(t_push_swap *ps);
void	build_stack_a_and_b(t_push_swap *ps, unsigned int size, \
							char **args, char split);

#endif