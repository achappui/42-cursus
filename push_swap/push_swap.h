/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2023/11/30 11:48:49 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# define WHITE_SPACES " \t\n\v\f\r"

# define S_A		"sa\n"
# define S_B		"sb\n"
# define S_BOTH		"ss\n"

# define P_A		"pa\n"
# define P_B		"pb\n"

# define R_A		"ra\n"
# define R_B		"rb\n"
# define R_BOTH		"rr\n"

# define RR_A		"rra\n"
# define RR_B		"rrb\n"
# define RR_BOTH	"rrr\n"

typedef struct s_intlist
{
	int					elem;
	struct s_intlist	*next;
}	t_intlist;

typedef struct s_statcks
{
	struct s_intlist	*stack_a;
	unsigned int		len_a;
	struct s_intlist	*stack_b;
	unsigned int		len_b;
}	t_stacks;

void	bubble_sort(t_stacks *s);

void	push(t_stacks *s, const char *txt);
void	swap(t_stacks *s, const char *txt);
void	rotate(t_stacks *s, const char *txt);
void	reverse_rotate(t_stacks *s, const char *txt);

char	receive_inputs_a(t_stacks *s, unsigned int size, char **args);
char	receive_inputs_b(t_stacks *s, char *arg1);

void	error_handler(t_stacks *s);

#endif