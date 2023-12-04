/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2023/12/04 17:13:32 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"

# define WHITE_SPACES " \t\n\v\f\r"

# define A		0
# define B		1
# define BOTH	2

typedef struct	s_stack
{
	int				*stack;
	unsigned int	mem_size;
	unsigned int	top;
	unsigned int	size;
}	t_stack;

typedef struct	s_checker
{
	t_list			*steps;
	struct s_stack	a;
	struct s_stack	b;
}	t_checker;

void	build_stack_a_and_b(t_checker *c, unsigned int size, char **args, char split);

void	push(t_checker *c, char which);
void	swap(t_checker *c, char which);
void	rotate(t_checker *c, char which);
void	reverse_rotate(t_checker *c, char which);

void	check_and_get_steps(t_checker *c);
void	run_steps(t_checker *c);

void	error_handler(t_checker *c);

#endif