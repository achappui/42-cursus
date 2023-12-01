/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2023/12/01 10:59:25 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# define WHITE_SPACES " \t\n\v\f\r"

//# define test s->top_b //possible ou pas

# define SA		"sa\n"
# define SB		"sb\n"
# define SS		"ss\n"

# define PA		"pa\n"
# define PB		"pb\n"

# define RA		"ra\n"
# define RB		"rb\n"
# define RR		"rr\n"

# define RRA	"rra\n"
# define RRB	"rrb\n"
# define RRR	"rrr\n"

typedef struct s_stacks
{
	unsigned int	buff_size;
	int				*stack_a;
	unsigned int	top_a;
	unsigned int	size_a;
	int				*stack_b;
	unsigned int	top_b;
	unsigned int	size_b;
}	t_stacks;

void	bubble_sort(t_stacks *s);

void	push(t_stacks *s, const char *txt);
void	swap(t_stacks *s, const char *txt);
void	rotate(t_stacks *s, const char *txt);
void	reverse_rotate(t_stacks *s, const char *txt);

char	init_inputs(t_stacks *s, unsigned int size, char **args, char split);

void	error_handler(t_stacks *s);

#endif