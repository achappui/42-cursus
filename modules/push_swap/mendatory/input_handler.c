/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:59 by achappui          #+#    #+#             */
/*   Updated: 2023/12/21 22:15:20 by achappui         ###   ########.fr       */
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

static char	make_stacks(t_push_swap *ps, unsigned int size, char **args)
{
	unsigned int	i;

	ps->a.stack = (int *)malloc(ps->a.mem_size * sizeof(int));
	if (!ps->a.stack)
		return (0);
	ps->b.stack = (int *)malloc(ps->b.mem_size * sizeof(int));
	if (!ps->b.stack)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!valid_int(args[i]))
			return (0);
		ps->a.stack[i] = ft_atoi(args[i]);
		if (already_in(ps->a.stack, i, ps->a.stack[i]))
			return (0);
		i++;
	}
	return (1);
}

void	build_stack_a_and_b(t_push_swap *ps, unsigned int size, char **args, char split)
{
	char	ok;

	if (split)
	{
		args = ft_split(*args, WHITE_SPACES);
		if (!args)
			error_handler(ps);
		size = 0;
		while (args[size] != NULL)
			size++;
	}
	ps->a.mem_size = size + 1;
	ps->b.mem_size = size + 1;
	ps->a.size = size;
	if (size)
		ok = make_stacks(ps, size, args);
	if (split)
	{
		size = 0;
		while (args[size] != NULL)
			free(args[size++]);
		free(args);
	}
	if (size && !ok)
		error_handler(ps);
}
