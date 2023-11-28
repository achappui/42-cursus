/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:59 by achappui          #+#    #+#             */
/*   Updated: 2023/11/28 13:59:32 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	valid_int(const char *str, const char *int_max)
{
	unsigned int	len;
	unsigned int	i;
	char			sign;

	sign = '+';
	if (*str == '+' || str == '-')
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
	if (len == 10 && \
		((i < 9 && (str[i] > int_max[i])) || \
		(i == 9 && str[i] == '8' && sign == '+') || \
		(i == 9 && str[i] > '8')))
		return (0);
	return (1);
}

static char	already_in(int elem, unsigned int size, t_stacks *s)
{
	while (++size < s->size_a)
		if (s->stack_a[size] == elem)
			return (1);
	return (0);
}

char	format_input(t_stacks *s, unsigned int size, char **args)
{
	s->stack_a = (int *)malloc((size) * sizeof(int));
	if (!s->stack_a)
		return (0);
	s->stack_b = (int *)malloc((size) * sizeof(int));
	if (!s->stack_b)
		return (0);
	s->size_a = size;
	while (--size >= 0)
	{
		if (!valid_int(args[size], "2147483647"))
			return (0);
		s->stack_a[size] = ft_atoi(args[size]);
		if (already_in(s->stack_a[size], size, s))
			return (0);
	}
}

char	split_format_input(t_stacks *s, char *arg1)
{
	unsigned int	i;
	char			**split_tab;

	split_tab = ft_split(arg1, WHITE_SPACES);
	if (!split_tab)
		return (0);
	i = 0;
	while (split_tab[i] != NULL)
		i++;
	if (!format_input(s, i, split_tab))
	{
		i = 0;
		while (split_tab[i] != NULL)
			free(split_tab[i++]);
		free(split_tab);
		return (0);
	}
	i = 0;
	while (split_tab[i] != NULL)
		free(split_tab[i++]);
	free(split_tab);
	return (1);
}
