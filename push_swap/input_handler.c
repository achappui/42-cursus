/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:59 by achappui          #+#    #+#             */
/*   Updated: 2023/11/27 22:52:50 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	error_handler(t_satcks *s, char err)
{
	if (err == 1)
		exit(write(2, "Error\n", 6));
	else if (err == 2)
	{
		free(s->stack_a);
		exit(write(2, "Error\n", 6));
	}
	else if (err == 3)
	{
		free(s->stack_a);
		free(s->stack_b);
		exit(write(2, "Error\n", 6));
	}
}

static char	valid_int(const char *str, const char *int_max)
{
	size_t			len;
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

static char	already_in(int integer, unsigned int start, t_satcks *s)
{
	while (++start < s->size_a)
		if (s->stack_a[start] == integer)
			return (1);
	return (0);
}

void	input_formater(t_satcks *s, int	argc, char *argv[])
{
	if (argc-- == 2)
	{
		argv = ft_split(argv[1], WHITE_SPACES);
		argc = 0;
		while (argv[argc] != NULL)
			argc++;
	}
	else
		argv++;
	s->stack_a = (int *)malloc((argc) * sizeof(int));
	if (!s->stack_a)
		error_handler(s, 1);
	s->size_a = argc;
	s->stack_b = (int *)malloc((argc) * sizeof(int));
	if (!s->stack_b)
		error_handler(s, 2);
	s->size_b = 0;
	while (--argc >= 0)
	{
		if (!valid_int(argv[argc], "2147483647"))
			error_handler(s, 3);
		s->stack_a[argc] = ft_atoi(argv[argc]);
		if (already_in(s->stack_a[argc], argc, s))
			error_handler(s, 3);
	}
}