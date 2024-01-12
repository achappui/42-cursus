/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:15:33 by achappui          #+#    #+#             */
/*   Updated: 2024/01/12 12:59:54 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_convert_float_to_uint(float f)
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

static int	get_exponent(unsigned int	uint_float)
{
	int				exponent;
	int				expo_mask;
	unsigned int	uint_float_mask;
	unsigned int	i;

	i = 0;
	exponent = 0;
	expo_mask = 1 << 7;
	uint_float_mask = 1U << 31;
	while (i < 8)
	{
		if (uint_float & uint_float_mask)
			exponent |= expo_mask;
		uint_float_mask >> 1;
		expo_mask >> 1;
		i++;
	}
	return (exponent - 127);
}

int ft_print_float(float n, t_options *o)
{
    unsigned int    uint_float;
    int				sign;
    int				exponent;

    uint_float = ft_convert_float_to_uint(n);
	sign = ((uint_float & 2147483648U) > 0);
	exponent = get_exponent(uint_float);

}