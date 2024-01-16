/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:07:54 by achappui          #+#    #+#             */
/*   Updated: 2024/01/11 11:30:50 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calcul_integer_options(char len, char prefix_len, t_options *o)
{
	o->width -= len + prefix_len;
	o->precision -= len;
	if (o->precision < 0)
		o->precision = 0;
	o->width -= o->precision;
	if (o->width < 0)
		o->width = 0;
	if (!(o->flags & F_MINUS) && !(o->flags & F_PRECISION) && \
		(o->flags & F_ZERO))
	{
		o->precision = o->width;
		o->width = 0;
	}
}

// else if (n == 0 && o->spe != 'd' && o->spe != 'i')
// 	o->flags &= ~F_HASHTAG;
int	ft_print_uint(unsigned long long n, t_options *o)
{
	char		tab[MAX_OCTAL_LLLEN];
	const char	base[17];
	short		i;

	base = "0123456789abcdef";
	i = sizeof(tab);
	while (n > 0 || (i == sizeof(tab) && !(o->flags & F_PRECISION)))
	{
		tab[--i] = base[(n % blen)];
		n /= blen;
	}
	n = sizeof(tab) - i;
	base += blen;
	calcul_integer_options(n, *base * (o->flags & F_HASHTAG), o);
	if ((!(o->flags & F_MINUS) && ft_putchars(spaces, ' ') == -1) \
		|| ((o->flags & F_HASHTAG) && write(1, base + 1, *base) == -1) \
		|| ft_putchars(zeroes, '0') == -1 \
		|| write(1, tab + i, n) == -1 \
		|| ((o->flags & F_MINUS) && ft_putchars(spaces, ' ') == -1))
		return (-1);
	return (o->width + o->precision + n + *base * (o->flags & F_HASHTAG));
}

int	ft_print_sint(long long n, t_options *o)
{
	o->flags |= F_HASHTAG;
	if (n < 0)
		return (ft_print_uint(-n, o));
	else if (o->flags & F_PLUS)
		return (ft_print_uint(n, o));
	else if (o->flags & F_SPACE)
		return (ft_print_uint(n, o));
	else
		return (ft_print_uint(n, o));
}

int	ft_print_ptr(uintptr_t n, t_options *o)
{
	o->flags |= F_HASHTAG;
	return(ft_print_uint(n, LOW_HEX, 16, o));
}