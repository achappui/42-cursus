/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2024/01/17 15:39:59 by achappui         ###   ########.fr       */
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

# define INS_BUFFER_SIZE	5000

typedef struct s_stack
{
	int				*stack;
	unsigned int	mem_size;
	unsigned int	top;
	unsigned int	size;
}	t_stack;

typedef struct s_ins_list
{
	char				buffer[INS_BUFFER_SIZE];
	unsigned int		used_space;
	struct s_ins_list	*next;
}	t_ins_block;

typedef struct s_push_swap
{
	struct s_stack		a;
	struct s_stack		b;
	struct s_ins_list	ins_list;
	struct s_ins_list	*first;
	struct s_ins_list	*current;
}	t_push_swap;

char	already_sorted(t_stack *s);
void	init_instructions_list(t_push_swap	*ps);
void	free_instructions_list(t_push_swap *ps);
void	print_instructions(t_push_swap	*ps);
void	error_handler(t_push_swap *ps);

void	init_stack(t_stack *s);
void	free_stacks(t_push_swap *ps);
void	input_error_handler(t_push_swap *ps, t_list *list);
void	fill_stack_a(t_push_swap *ps, t_list *list);
void	input_handler(t_push_swap *ps, int argc, char *argv[]);

int		*radix_sort(int arr[], unsigned int size);
void	sort_only_three_a(t_push_swap *ps);
void	replace_by_index(t_push_swap *ps);
void	sorting_algo(t_push_swap *ps);
void	midpoint_chunker(t_push_swap *ps);
void	rotate_to_sorted(t_push_swap *ps);

void	push(t_push_swap *ps, char which);
void	swap(t_push_swap *ps, char which);
void	rotate(t_push_swap *ps, char which);
void	reverse_rotate(t_push_swap *ps, char which);

#endif