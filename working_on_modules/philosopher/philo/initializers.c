/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:01:38 by achappui          #+#    #+#             */
/*   Updated: 2024/02/11 10:48:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	init_inputs(t_datas *datas, int argc, char *argv[])
{
	int	i;

	if (argc != 5 && argc != 6)
		return (0 * write(1, "ERROR: invalid arguments\n", 25));
	i = 0;
	while (++i < argc)
		if (!valid_ushort(argv[i]))
			return (0 * write(1, "ERROR: invalid argument type\n", 29));
	datas->nb_of_philo = ft_uatoi(argv[1]);
	if (datas->nb_of_philo > 200 || datas->nb_of_philo < 1)
		return (0 * write(1, "ERROR: 1 <= nb_of_philo <= 200\n", 31));
	datas->time_to_die = ft_uatoi(argv[2]);
	datas->time_to_eat = ft_uatoi(argv[3]) * 1000;
	datas->time_to_sleep = ft_uatoi(argv[4]) * 1000;
	if (argc == 6)
	{
		datas->meal_limit = ft_uatoi(argv[5]);
		if (datas->meal_limit == 0)
			return (0 * write(1, "ERROR: 1 <= meal_limit\n", 23));
	}
	else
		datas->meal_limit = NO_MEAL_LIMIT;
	return (1);
}

char	init_forks(t_datas *datas)
{
	unsigned int	i;

	datas->forks = (pthread_mutex_t *)malloc(datas->nb_of_philo * sizeof(pthread_mutex_t));
	if (!datas->forks)
		return (0 * write(1, "ERROR: malloc\n", 14));
	i = 0;
	while (i < datas->nb_of_philo)
		pthread_mutex_init(&datas->forks[i++], NULL);
	return (1);
}

char	init_philosophers(t_datas *datas)
{
	unsigned int	i;

	datas->philos = (t_philo *)malloc(datas->nb_of_philo * sizeof(t_philo));
	if (!datas->philos)
		return (0 * write(1, "ERROR: malloc\n", 14));
	i = 0;
	while (i < datas->nb_of_philo)
	{
		datas->philos[i].id = i + 1;
		datas->philos[i].meal_counter = 0;
		datas->philos[i].last_meal = 0;
		datas->philos[i].right_fork = &datas->forks[(i + 1) % datas->nb_of_philo];
		datas->philos[i].left_fork = &datas->forks[i];
		datas->philos[i].datas = datas;
		if (!(i & 1) && i < datas->nb_of_philo - 1)
			datas->philos[i].eating_permission = 1;
		else
			datas->philos[i].eating_permission = 0;
		i++;
	}
	i = -1;
	while (++i < datas->nb_of_philo)
		pthread_create(&datas->philos[i].thread, NULL, &philosopher_thread, &datas->philos[i]); //check la reussite
	return (1);
}

char	init_datas(t_datas *datas, int argc, char *argv[])
{
	if (!init_inputs(datas, argc, argv))
		return (0);
	datas->end_routine = 0;
	datas->finished_eating = 0;
	datas->limit_reached = 0;
	datas->permission_index = 0;
	pthread_mutex_init(&datas->message_lock, NULL); //checker les mutex
	pthread_mutex_init(&datas->permission_lock, NULL);
	gettimeofday(&datas->start_time, NULL);
	if (!init_forks(datas))
		return (0);
	if (!init_philosophers(datas))
		return (0);
	return (1);
}
