/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2023/11/27 22:54:26 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define WHITE_SPACES	"\009\010\011\012\013\032"

typedef struct s_satcks
{
	int				*stack_a;
	unsigned int	size_a;
	int				*stack_b;
	unsigned int	size_b;
}	t_satcks;


void	input_formater(t_satcks *s, int	argc, char *argv[]);

#endif