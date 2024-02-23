/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:17 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 01:09:02 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	ft_uatoi(const char *str)
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

static char	valid_ushort(const char *str)
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

char	error_inputs_handler(char err_no)
{
	if (err_no == 1)
		write(2, "ERROR: invalid argument number\n", 31);
	else if (err_no == 2)
		write(2, "ERROR: arguments must be of type unsigned short\n", 48);
	else if (err_no == 3)
		write(2, "ERROR: too much philosophers (max is 1000)\n", 43);
	else if (err_no == 4)
		write(2, "ERROR: not enough philosopher (min is 1)\n", 41);
	return (0);
}

char	input_handler(t_datas *datas, int argc, char *argv[])
{
	int	i;

	if (argc != 5 && argc != 6)
		return (error_inputs_handler(1));
	i = 0;
	while (++i < argc)
		if (!valid_ushort(argv[i]))
			return (error_inputs_handler(2));
	datas->nb_of_philo = ft_uatoi(argv[1]);
	if (datas->nb_of_philo > 1000)
		return (error_inputs_handler(3));
	if (datas->nb_of_philo == 0)
		return (error_inputs_handler(4));
	datas->time_to_die = ft_uatoi(argv[2]);
	datas->time_to_eat = ft_uatoi(argv[3]) * 1000;
	datas->time_to_sleep = ft_uatoi(argv[4]) * 1000;
	datas->end_status = 0;
	gettimeofday(&datas->start_time, NULL);
	if (argc == 6)
		datas->meal_limit = ft_uatoi(argv[5]);
	else
		datas->meal_limit = NO_MEAL_LIMIT;
	pthread_mutex_init(&datas->locker, NULL);
	return (1);
}
