/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:01:38 by achappui          #+#    #+#             */
/*   Updated: 2024/02/11 19:43:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	init_inputs(t_datas *datas, int argc, char *argv[])
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

char	init_datas(t_datas *datas, int argc, char *argv[])
{
	if (!init_inputs(datas, argc, argv))
		return (0);
	datas->end_status = 0;
	datas->finished_eating = 0;
	if (pthread_mutex_init(&datas->global_lock, NULL) != 0) //checker que ca reussi
		return (0 * write(1, "ERROR: pthread_mutex_init\n", 26));
	gettimeofday(&datas->start_time, NULL);
	return (1);
}

char	init_forks(t_datas *datas, t_fork **forks)
{
	unsigned int	i;

	*forks = (t_fork *)malloc(datas->nb_of_philo * sizeof(t_fork)); //a checker le malloc
	if (!*forks)
		return (0 * write(1, "ERROR: malloc\n", 14));
	i = -1;
	while (++i < datas->nb_of_philo)
		pthread_mutex_init(&(*forks)[i], NULL);
	return (1);
}

static void	swap_forks(t_fork **fork1, t_fork **fork2)
{
	t_fork	*tmp;

	tmp = *fork1;
	*fork1 = *fork2;
	*fork2 = tmp;
}

char	invite_philosophers(t_datas *datas, t_philo **philos, t_fork *forks)
{
	unsigned int	i;

	*philos = (t_philo *)malloc(datas->nb_of_philo * sizeof(t_philo));
	if (!*philos)
		return (0 * write(1, "ERROR: malloc\n", 14));
	i = 0;
	while (i < datas->nb_of_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meal_counter = 0;
		(*philos)[i].last_meal = 0;
		(*philos)[i].sync = -1;
		(*philos)[i].right_fork = &forks[(i + 1) % datas->nb_of_philo];
		(*philos)[i].left_fork = &forks[i];
		if (i & 1)
			swap_forks(&(*philos)[i].right_fork, &(*philos)[i].left_fork);
		(*philos)[i].datas = datas;
		pthread_create(&(*philos)[i].philo_thread, NULL, &philosopher_thread, &(*philos)[i]); //a checker le pthread create et gerer l'erreur
		i++;
	}
	return (1);
}