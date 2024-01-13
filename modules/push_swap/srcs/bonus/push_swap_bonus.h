/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2024/01/13 19:57:31 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../../libs/libft/libft.h"

# define WHITE_SPACES 			" \t\n\v\f\r"
# define A						'a'
# define B						'b'
# define BOTH					'c'

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

void	input_error_handler(t_push_swap *ps, t_list *list);
void	fill_stack_a(t_push_swap *ps, t_list *list);
void	input_handler(t_push_swap *ps, int argc, char *argv[]);
void	push(t_push_swap *ps, char which);
void	swap(t_push_swap *ps, char which);
void	rotate(t_push_swap *ps, char which);
void	reverse_rotate(t_push_swap *ps, char which);
void	run_steps(t_push_swap *ps);
void	error_handler(t_push_swap *ps);
void	build_stack_a_and_b(t_push_swap *ps, unsigned int size, \
								char **args, char split);

#endif