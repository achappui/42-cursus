/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:24:30 by achappui          #+#    #+#             */
/*   Updated: 2024/01/17 19:47:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->mem_size = 0;
	s->stack = NULL;
	s->size = 0;
	s->top = 0;
}

void	free_stacks(t_push_swap *ps)
{
	if (ps->a.stack)
		free(ps->a.stack);
	if (ps->b.stack)
		free(ps->b.stack);
}

static char	valid_int(const char *str)
{
	int			sign;
	long long	number;
	
	number = 0;
	sign = 1;
	if (*str == '+')
	    str++;
	else if (*str == '-' && str++)
	    sign = -1;
	if (*str == '\0')
	    return (0);
	while (*str == '0')
	    str++;
	if (ft_strlen(str) > 10)
	    return (0);
	while (*str)
	{
	    if (!(*str >= '0' && *str <= '9'))
	        return (0);
	   number *= 10;
	   number += *str++ - '0';
	}
	if (number * sign  < INT32_MIN || number * sign > INT32_MAX)
	    return (0);
	return (1);
}

static char	already_in(int *stack, unsigned int i, int elem)
{
	while (i > 0)
		if (stack[--i] == elem)
			return (1);
	return (0);
}

void	fill_stack_a(t_push_swap *ps, t_list *list)
{
	unsigned int	i;
	unsigned int	j;
	t_list			*begin;

	begin = list;
	i = 0;
	list = list->next;
	while (list)
	{
		j = 0;
		while (((char **)list->content)[j] != NULL)
		{
			if (!valid_int(((char **)list->content)[j]))
				input_error_handler(ps, begin->next);
			ps->a.stack[i] = ft_atoi(((char **)list->content)[j]);
			if (already_in(ps->a.stack, i, ps->a.stack[i]))
				input_error_handler(ps, begin->next);
			j++;
			i++;
		}
		list = list->next;
	}
}
