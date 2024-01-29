/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:17 by achappui          #+#    #+#             */
/*   Updated: 2024/01/29 14:41:29 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static unsigned int	ft_uatoi(const char *str)
{
	unsigned int	number;

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

static char	valid_uint(const char *str)
{
	unsigned long long	number;

	number = 0;
	if (*str == '+')
	    str++;
	if (*str == '\0')
	    return (0);
	while (*str == '0')
	    str++;
	if (ft_strlen(str) > 10)
	    return (0);
	while (*str)
	{
	    if (!(*str >= '0' && *str <= '9'))
	        return (0);
	   number *= 10;
	   number += *str++ - '0';
	}
	if (number > )
	    return (0);
	return (1);
}

char	input_handler(t_inputs *inputs, int argc, char *argv[])
{
	if (argc != 5 || argc != 6)
		return (write(2, "Invalid arguments !\n", 20));
	if (argc == 6)
		inputs->eat_is_limited = 1;
	else
		inputs->eat_is_limited = 0;
	while (--argc > 0)
		if (!valid_uint(argv[argc]))
			return (write(2, "Arguments must be of type unsigned int !\n", 33));
	inputs->number_of_philosophers = ft_uatoi(argv[1]);
	inputs->time_to_die = ft_uatoi(argv[2])  * 1000;
	inputs->time_to_eat = ft_uatoi(argv[3])  * 1000; //changer le * 1000, determiner un nombre de micro seconde max
	inputs->time_to_sleep = ft_uatoi(argv[4])  * 1000; //poser des limits max et min pour chaque arguments
	if (inputs->eat_is_limited)
		inputs->number_of_times_each_philosopher_must_eat = ft_uatoi(argv[5]);
	inputs->start = 0;
	return (OK);
}
