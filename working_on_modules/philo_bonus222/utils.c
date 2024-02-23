/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:39:12 by achappui          #+#    #+#             */
/*   Updated: 2024/02/22 13:50:39 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	get_time(struct timeval *start_time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - \
			(start_time->tv_sec * 1000 + start_time->tv_usec / 1000);
}

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