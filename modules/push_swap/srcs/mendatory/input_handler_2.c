/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:24:30 by achappui          #+#    #+#             */
/*   Updated: 2024/01/13 20:03:04 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	valid_int(const char *str)
{
	const char		*int_max;
	unsigned int	len;
	unsigned int	i;
	char			sign;

	int_max = "2147483647";
	sign = '+';
	if (*str == '+' || *str == '-')
		sign = *str++;
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	len = -1;
	while (str[++len] != '\0')
		if (str[len] < '0' || str[len] > '9')
			return (0);
	if (len > 10 || len == 0)
		return (0);
	i = 0;
	while (str[i] == int_max[i])
		i++;
	if (len == 10 && ((i < 9 && (str[i] > int_max[i])) || \
		(i == 9 && str[i] == '8' && sign == '+') || \
		(i == 9 && str[i] > '8')))
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
