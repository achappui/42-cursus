/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:04:19 by achappui          #+#    #+#             */
/*   Updated: 2024/01/15 12:49:30 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static long long	validate_base10(const char *s, int sign)
{
	long long	number;

	number = 0;
	while (*s != '\0')
	{
		number *= 10;
		if (*s >= '0' && *s <= '9')
			number += *s - '0';
		else
			return (INVALID);
		if (number * sign > INT_MAX || number * sign < INT_MIN)
			return (INVALID);
		s++;
	}
	return (number);
}

static long long	validate_basehexa(const char *s, int sign)
{
	long long	number;

	number = 0;
	while (*s != '\0')
	{
		number *= 16;
		if (*s >= 'A' && *s <= 'F')
			number += *s - 55;
		else if (*s >= 'a' && *s <= 'f')
			number += *s - 87;
		else if (*s >= '0' && *s <= '9')
			number += *s - '0';
		else
			return (INVALID);
		if (number * sign > INT_MAX || number * sign < INT_MIN)
			return (INVALID);
		s++;
	}
	return (number);
}

static long long	validate_octal(const char *s, int sign)
{
	long long	number;

	number = 0;
	while (*s != '\0')
	{
		number *= 8;
		if (*s >= '0' && *s <= '7')
			number += *s - '0';
		else
			return (INVALID);
		if (number * sign > INT_MAX || number * sign < INT_MIN)
			return (INVALID);
		s++;
	}
	return (number);
}

static long long	validate_binary(const char *s, int sign)
{
	long long	number;

	number = 0;
	while (*s != '\0')
	{
		number *= 2;
		if (*s == '0' || *s == '1')
			number += *s - '0';
		else
			return (INVALID);
		if (number * sign > INT_MAX || number * sign < INT_MIN)
			return (INVALID);
		s++;
	}
	return (number);
}

long long validate_int(const char *s)
{
	int			sign;
	long long	number;

	sign = 1;
	if (*s == '-' && s++)
		sign = -1;
	else if (*s == '+')
		s++;
	if (*s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X') && \
		*(s + 2) != '\0' && s++ && s++)
		number = validate_basehexa(s, sign);
	else if (*s == '0' && (*(s + 1) == 'b' || *(s + 1) == 'B') && \
			*(s + 2) != '\0' && s++ && s++)
		number = validate_binary(s, sign);
	else if (*s == '0' && *(s + 1) != '\0' && s++)
		number = validate_octal(s, sign);
	else if (*s != '\0')
		number = validate_base10(s, sign);
	else
		return (INVALID);
	if (number == INVALID)
		return (INVALID);
	return (number * sign);
}
