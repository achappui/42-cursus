/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:13:20 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 01:06:05 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	run_half_philo(t_datas *datas, t_philo *philos, t_fork *forks, \
							int which)
{
	unsigned int	i;

	i = which;
	while (i < datas->nb_of_philo)
	{
		philos[i].last_meal = 0;
		philos[i].id = i + 1;
		philos[i].meal_counter = 0;
		philos[i].right_fork = &forks[(i + 1) % datas->nb_of_philo];
		philos[i].left_fork = &forks[i];
		philos[i].still_eating = 1;
		philos[i].datas = datas;
		pthread_create(&philos[i].philo_thread, NULL, &philosopher_routine, \
		&philos[i]);
		i += 2;
	}
}

void	run_philos(t_datas *datas, t_philo **philos, t_fork *forks)
{
	*philos = (t_philo *)malloc(datas->nb_of_philo * sizeof(t_philo));
	run_half_philo(datas, *philos, forks, ODD);
	usleep(HALF_ADVANTAGE);
	run_half_philo(datas, *philos, forks, EVEN);
}
