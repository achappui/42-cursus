/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_printers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:18:01 by achappui          #+#    #+#             */
/*   Updated: 2024/01/10 20:18:19 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

To print a float/double number in binary, use the flag 0;

*/
#include "ft_printf.h"

int	ft_print_binary_integer(unsigned long long n, t_options *o, short size)
{
	char				tab[71];
	unsigned long long	mask;
	short				i;
	short				count;

	count = 0;
	i = sizeof(tab);
	mask = 1ULL;
	while (count++ < size)
	{
		tab[--i] = ((n & mask) > 0) + '0';
		mask *= 2;
		if ((o->flags & F_SPACE) && count != size && count % 8 == 0)
			tab[--i] = ' ';
	}
	n = sizeof(tab) - i;
	o->width -= (int)n + 2 * (o->flags & F_HASHTAG);
	if (o->width < 0)
		o->width = 0;
	if ((!(o->flags & F_MINUS) && ft_putchars(o->width, ' ') == -1) || \
		((o->flags & F_HASHTAG) && write(1, "0b", 2) != 2) || \
		write(1, tab + i, n) != (ssize_t)n || \
		((o->flags & F_MINUS) && ft_putchars(o->width, ' ') == -1))
		return (-1);
	return (o->width + n + 2 * (o->flags & F_HASHTAG));
}



int	ft_print_binary_float(float n, t_options *o)
{
	char				tab[71];
	unsigned long long	mask;
	short				i;
	short				count;

	count = 0;
	i = sizeof(tab);
	mask = 1ULL;
	ft_binary_precision_calcul(o);
	while (o->precision--)
	{
		if ((o->flags & F_SPACE) && count && count % 8 == 0)
			tab[--i] = ' ';
		tab[--i] = ((n & mask) > 0) + '0';
		mask *= 2;
		count++;
	}
	n = sizeof(tab) - i;
	o->width -= (int)n + 2 * (o->flags & F_HASHTAG);
	if (o->width < 0)
		o->width = 0;
	if ((!(o->flags & F_MINUS) && ft_putchars(o->width, ' ') == -1) || \
		((o->flags & F_HASHTAG) && write(1, "0b", 2) != 2) || \
		write(1, tab + i, n) != (ssize_t)n || \
		((o->flags & F_MINUS) && ft_putchars(o->width, ' ') == -1))
		return (-1);
	return (o->width + n + 2 * (o->flags & F_HASHTAG));
}