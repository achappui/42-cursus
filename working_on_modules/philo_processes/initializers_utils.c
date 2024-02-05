/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:12:03 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 19:49:41 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_uatoi(const char *str)
{
	int	number;

	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - 48;
		str++;
	}
	return (number);
}

char	valid_ushort(const char *str)
{
	unsigned int	number;

	number = 0;
	if (*str == '+')
	    str++;
	if (*str == '\0')
	    return (0);
	while (*str == '0')
	    str++;
	if (ft_strlen(str) > 5)
	    return (0);
	while (*str)
	{
	    if (!(*str >= '0' && *str <= '9'))
	        return (0);
	   number *= 10;
	   number += *str++ - '0';
	}
	if (number > 65535)
	    return (0);
	return (1);
}

void	error_input(char err_no)
{
	if (err_no == 1)
		write(1, "ERROR: invalid number of argument\n", 34);
	else if (err_no == 2)
		write(1, "ERROR: arguments must be of type unsigned short\n", 48);
	else if (err_no == 3)
		write(1, "ERROR: too much philosophers (1000 max)\n", 40);
	else if (err_no == 4)
		write(1, "ERROR: not enough philosophers (1 min)\n", 39);
	exit(1);
}