/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:18:15 by achappui          #+#    #+#             */
/*   Updated: 2024/01/10 20:19:06 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_float(float n, t_options *o)
{
	unsigned int	*f_tab;
	char			sign;

	f_tab = &n;
	if ()
	








	calcul_integer_options(n, *base * (o->flags & F_HASHTAG), o);
	if ((!(o->flags & F_MINUS) && ft_putchars(o->width, ' ') == -1) || \
		((o->flags & F_HASHTAG) && write(1, base + 1, *base) != *base) || \
		ft_putchars(o->precision, '0') == -1 || \
		write(1, tab + i, n) != (ssize_t)n || \
		((o->flags & F_MINUS) && ft_putchars(o->width, ' ') == -1))
		return (-1);
	return (o->width + o->precision + n + *base * (o->flags & F_HASHTAG));
}