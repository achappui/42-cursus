/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:59 by achappui          #+#    #+#             */
/*   Updated: 2023/11/30 18:50:04 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	free_split(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (1);
}

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

static char	already_in(int *stack, unsigned int index, int integer)
{
	while (index > 0)
		if (stack[--index] == integer)
			return (1);
	return (0);
}

static char	fill_stack_a(t_stacks *s, unsigned int size, char **args)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (!valid_int(args[i]))
			return (0);
		s->ptr_a[i] = ft_atoi(args[i]);
		if (already_in(s->ptr_a, i, s->ptr_a[i]))
			return (0);
		i++;
	}
	return (1);
}

char	init_inputs(t_stacks *s, unsigned int size, char **args, char split)
{
	if (split)
	{
		args = ft_split(args[1], WHITE_SPACES);
		if (!args)
			return (0);
		while (args[size] != NULL)
			size++;
	}
	s->ptr_a = NULL;
	s->ptr_b = NULL;
	s->ptr_a = (int *)malloc((size + 1) * sizeof(int));
	if (!s->ptr_a)
		return (0);
	s->ptr_b = (int *)malloc((size + 1) * sizeof(int));
	if (!s->ptr_b)
		return (0);
	s->size = size + 1;
	s->h_a = 0;
	s->h_b = 0;
	s->t_a = size - 1;
	s->t_b = 0;
	if (split)
		return (fill_stack_a(s, size, args) && free_split(args));
	return (fill_stack_a(s, size, args));
}

