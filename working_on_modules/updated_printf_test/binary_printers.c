/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_printers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:18:01 by achappui          #+#    #+#             */
/*   Updated: 2024/01/12 10:40:24 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

To print a float/double number in binary, use the flag 0;

*/
#include "ft_printf.h"

int	ft_print_binary_integer(unsigned long long n, t_options *o)
{
	char				tab[71];
	unsigned long long	mask;
	short				i;
	short				count;

	count = 0;
	i = sizeof(tab);
	mask = 1ULL;
	while (o->precision--)
	{
		if ((o->flags & F_SPACE) && o->precision && count % 8 == 0)
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

unsigned int	ft_convert_float_to_uint(float f)
{
	unsigned int	uinteger;
	void			*f_tab;
	unsigned int	mask;

	f_tab = &f;
	uinteger = 0;
	mask = 1U;
	while (mask < 2147483648U)
	{
		if (*(unsigned int *)f_tab & mask)
			uinteger |= mask;
		mask *= 2;
	}
	if (*(unsigned int *)f_tab & mask)
		uinteger |= mask;
	return (uinteger);
}