/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:59 by achappui          #+#    #+#             */
/*   Updated: 2023/12/04 16:51:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static char	make_stacks(t_checker *c, unsigned int size, char **args)
{
	unsigned int	i;

	c->a.stack = (int *)malloc(c->a.mem_size * sizeof(int));
	if (!c->a.stack)
		return (0);
	c->b.stack = (int *)malloc(c->b.mem_size * sizeof(int));
	if (!c->b.stack)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!valid_int(args[i]))
			return (0);
		c->a.stack[i] = ft_atoi(args[i]);
		if (already_in(c->a.stack, i, c->a.stack[i]))
			return (0);
		i++;
	}
	return (1);
}


void	build_stack_a_and_b(t_checker *c, unsigned int size, char **args, char split)
{
	char	ok;

	if (split)
	{
		args = ft_split(*args, WHITE_SPACES);
		if (!args)
			error_handler(c);
		size = 0;
		while (args[size] != NULL)
			size++;
	}
	c->a.mem_size = size + 1;
	c->b.mem_size = size + 1;
	c->a.size = size;
	ok = make_stacks(c, size, args);
	if (split)
	{
		size = 0;
		while (args[size] != NULL)
			free(args[size++]);
		free(args);
	}
	if (!ok)
		error_handler(c);
}
