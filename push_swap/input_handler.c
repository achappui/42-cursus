/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:59 by achappui          #+#    #+#             */
/*   Updated: 2023/11/29 19:03:51 by achappui         ###   ########.fr       */
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
	if (*str == '+' || (uintptr_t)str == '-')
		sign = *str++;
	while (*str == '0' && (uintptr_t)*(str + 1) != '\0')
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

static char	already_in(t_intlist *lst, int number)
{
	while (lst)
	{
		if (lst->elem == number)
			return (1);
		lst = lst->next;
	}
	return (0);
}

char	receive_inputs_a(t_stacks *s, unsigned int size, char **args)
{
	t_intlist	*tmp;
	t_intlist	*new_elem;

	tmp = NULL;
	s->len_a = 0;
	while (--size >= 0)
	{
		if (!valid_int(args[size]))
			return (0);
		new_elem = (t_intlist *)malloc(sizeof(t_intlist));
		if (!new_elem)
			return (0);
		new_elem->elem = ft_atoi(args[size]);
		new_elem->next = tmp;
		tmp = new_elem;
		if (already_in(tmp->next, tmp->elem))
			return (0);
		s->len_a++;
	}
	s->stack_a = new_elem;
	s->len_b = 0;
	s->stack_b = NULL;
	return (1);
}

char	receive_inputs_b(t_stacks *s, char *arg1)
{
	unsigned int	i;
	char			**split_tab;

	split_tab = ft_split(arg1, WHITE_SPACES);
	//printf(" %c %c %c", split_tab[0][0], split_tab[1][0], split_tab[2][0]);
	if (!split_tab)
	{
		printf("yoo");
		return (0);
	}
	i = 0;
	while (split_tab[i] != NULL)
		i++;
	arg1 = (char *)(0 * (uintptr_t)arg1 + receive_inputs_a(s, i, split_tab));
	i = 0;
	printf("yoo");
	while (split_tab[i] != NULL)
	{
		//printf("I %d et test %c\n", i, split_tab[i][0]);
		free(split_tab[i++]);
	}
	free(split_tab);
	return ((uintptr_t)arg1);
}
