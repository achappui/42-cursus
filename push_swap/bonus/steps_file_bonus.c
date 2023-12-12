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

static char	valid_line(char *l)
{
	if ((((l[0] == 'p' && (l[1] == 'a' || l[1] == 'b')) || \
		(l[0] == 'r' && (l[1] == 'a' || l[1] == 'b' || l[1] == 'r')) || \ 
		(l[0] == 's' && (l[1] == 'a' || l[1] == 'b' || l[1] == 's'))) && \
		((l[2] == '\n' && l[3] == '\0') || l[2] == '\0')) || \
		(l[0] == 'r' && l[1] == 'r' && \
		(l[2] == 'a' || l[2] == 'b' || l[2] == 'r') && \
		((l[3] == '\n' && l[4] == '\0') || l[3] == '\0')))
		return (1);
	return (0);
}

void	run_steps(t_checker *c)
{
	t_list	*lst;
	char	*step;

	lst = c->steps;
	while (lst && lst->content) //a verifier normalement c'est bon
	{
		step = (char *)lst->content;
		if (step[0] == 'p')
			push(c, step[1]);
		else if (step[0] == 's')
			swap(c, step[1]);
		else if (step[0] == 'r' && (step[2] == '\n' || step[2] == '\0'))
			rotate(c, step[1]);
		else
			reverse_rotate(c, step[2])
		lst = lst->next;
	}
}

void	check_and_get_steps(t_checker *c)
{
	t_list			*lst;

	lst = ft_lstnew(get_next_line(0));
	if (!lst)
		error_handler(c);
	c->steps = lst;
	while (lst->content)
	{
		lst->next = ft_lstnew(get_next_line(0));
		if (!lst->next)
			error_handler(c);
		lst = lst->next;
	}
}