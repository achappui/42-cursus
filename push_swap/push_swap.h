/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2023/11/29 19:01:12 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# define WHITE_SPACES	"\032\009\010\011\012\013"

# define S_A		"sa"
# define S_B		"sb"
# define S_BOTH		"ss"

# define P_A		"pa"
# define P_B		"pb"

# define R_A		"ra"
# define R_B		"rb"
# define R_BOTH		"rr"

# define RR_A		"rra"
# define RR_B		"rrb"
# define RR_BOTH	"rrr"

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