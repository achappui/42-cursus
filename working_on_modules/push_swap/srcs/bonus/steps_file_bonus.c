/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:30:29 by achappui          #+#    #+#             */
/*   Updated: 2023/12/03 19:30:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	validate_and_execute_in(t_push_swap *ps, char *in)
{
	char	ok;

	ok = 0;
	if (((in[0] == 'p' && (in[1] == 'a' || in[1] == 'b')) || \
		(in[0] == 'r' && (in[1] == 'a' || in[1] == 'b' || in[1] == 'r')) || \
		(in[0] == 's' && (in[1] == 'a' || in[1] == 'b' || in[1] == 's'))) && \
		(in[2] == '\n' ))
		ok = in[0];
	else if (in[0] == 'r' && in[1] == 'r' && \
			(in[2] == 'a' || in[2] == 'b' || in[2] == 'r') && (in[3] == '\n'))
		ok = -1;
	if (!ok)
		error_handler(ps);
	else if (ok == 'p')
		push(ps, in[1]);
	else if (ok == 'r')
		rotate(ps, in[1]);
	else if (ok == 's')
		swap(ps, in[1]);
	else
		reverse_rotate(ps, in[2]);
}

void	run_steps(t_push_swap *ps)
{
	char		*in;

	in = get_next_line(0);
	while (in)
	{
		validate_and_execute_in(ps, in);
		free(in);
		in = get_next_line(0);
	}
}
