/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:52 by achappui          #+#    #+#             */
/*   Updated: 2023/11/28 14:02:48 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# define WHITE_SPACES	"\009\010\011\012\013\032"


typedef struct s_satcks
{
	int				*stack_a;
	unsigned int	size_a;
	unsigned int	top_a;
	int				*stack_b;
	unsigned int	size_b;
	unsigned int	top_b;
}	t_stacks;


char	format_input(t_satcks *s, unsigned int size, char **args);
char	split_format_input(t_satcks *s, char *arg1);

#endif