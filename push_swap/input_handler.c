/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:59 by achappui          #+#    #+#             */
/*   Updated: 2023/11/30 11:24:57 by achappui         ###   ########.fr       */
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
	//printf("Size %u\n", size);
	while (size > 0)
	{
		size--;
		printf("INDEX: %u\n", size);
		if (!valid_int(args[size]))
		{
			printf("NOT VALID");
			return (0);
		}
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
	char			return_value;
	char			**split_tab;
	unsigned int	i;

	split_tab = ft_split(arg1, WHITE_SPACES);
	//printf(" %c %c %c", split_tab[0][0], split_tab[1][0], split_tab[2][0]);
	if (!split_tab)
		return (0);
	i = 0;
	while (split_tab[i] != NULL)
	{
		//printf("Elem: %d, %s\n", i, split_tab[i]);
		i++;
	}
	//printf("size %d\n", i);
	return_value = receive_inputs_a(s, i, split_tab);
	i = 0;
	while (split_tab[i] != NULL)
	{
		//printf("I %d et test %c\n", i, split_tab[i][0]);
		free(split_tab[i++]);
	}
	free(split_tab);
	return (return_value);
}
