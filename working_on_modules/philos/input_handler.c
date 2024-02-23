/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:17 by achappui          #+#    #+#             */
/*   Updated: 2024/01/30 13:35:53 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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

void	print_inputs(t_datas *datas)
{
	printf("nb_of_philo: %d\n", datas->nb_of_philo);
	printf("die_time: %d\n", datas->die_time);
	printf("eat_time: %d\n", datas->eat_time);
	printf("sleep_time: %d\n", datas->sleep_time);
	printf("max_meal_nb: %d\n", datas->max_meal_nb);
	printf("no_meal_limit: %d\n", datas->no_meal_limit);
}

char	input_handler(t_datas *datas, int argc, char *argv[])
{
	int	i;

	if (argc != 5 && argc != 6)
		return (write(2, "Invalid number of argument !\n", 29));
	i = 0;
	while (++i < argc)
		if (!valid_ushort(argv[i]))
			return (write(2, "Arguments must be of type unsigned short !\n", 43));
	datas->nb_of_philo = ft_uatoi(argv[1]);
	datas->die_time = ft_uatoi(argv[2]) * 1000;
	datas->eat_time = ft_uatoi(argv[3]) * 1000;
	datas->sleep_time = ft_uatoi(argv[4]) * 1000;
	datas->no_meal_limit = 0;
	datas->max_meal_nb = 0; //pas necessaire
	if (argc == 6)
		datas->max_meal_nb = ft_uatoi(argv[5]);
	else
		datas->no_meal_limit = 1;
	print_inputs(datas);
	return (OK);
}
//poser des limits max et min pour chaque arguments
//changer le * 1000, determiner un nombre de micro seconde max
//pas poser de limits mais checker avec des grosses valeurs
