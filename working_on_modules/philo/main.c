/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:06:41 by achappui          #+#    #+#             */
/*   Updated: 2024/02/11 15:28:20 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	Je suis parti du principe que aucune fonction n'echoue.
*/

void	free_simulation(t_datas *datas, t_philo *philos, t_fork *forks)
{
	unsigned int	i;

	i = -1;
	while (++i < datas->nb_of_philo)
		pthread_join(philos[i].philo_thread, NULL);
	free(philos);
	i = -1;
	while (++i < datas->nb_of_philo)
		pthread_mutex_destroy(&forks[i]);
	free(forks);
	pthread_mutex_destroy(&datas->global_lock);
}

int	main(int argc, char *argv[])
{
	t_datas		datas;
	t_philo		*philos;
	t_fork		*forks;

	if (!init_datas(&datas, argc, argv))
		return (1);
	if (!init_forks(&datas, &forks))
		return (1);
	if (!invite_philosophers(&datas, &philos, forks))
		return (1);
	free_simulation(&datas, philos, forks);
	return (0);
}
