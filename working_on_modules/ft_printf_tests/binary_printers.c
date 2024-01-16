/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_printers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:18:01 by achappui          #+#    #+#             */
/*   Updated: 2024/01/12 11:16:46 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

To print a float/double number in binary, use the flag 0;

*/
#include "ft_printf.h"

unsigned int	calcul_size_binary(t_options *o)
{
	if (!(o->flags & F_PRECISION))
	{
		if (o->spe == 'p')
			return (64);
		else if (o->spe == 'c')
			return (8);
		return (32);
	}
	else if (o->precision > 64)
		return (64);
	else
		return (o->precision);
}

int	ft_print_binary_number(unsigned long long n, t_options *o, unsigned int size)
{
	char				tab[71];
	unsigned long long	mask;
	short				i;
	short				count;

	count = 0;
	i = sizeof(tab);
	mask = 1ULL;
	while (size--)
	{
		if ((o->flags & F_SPACE) && size && count % 8 == 0)
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
