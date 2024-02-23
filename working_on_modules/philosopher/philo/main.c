/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:06:41 by achappui          #+#    #+#             */
/*   Updated: 2024/02/11 10:58:11 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	Je suis parti du principe que aucune fonction n'echoue.
*/

void	free_all(t_datas *datas)
{
	unsigned int	i;

	i = 0;
	while (i < datas->nb_of_philo)
		pthread_join(datas->philos[i++].thread, NULL);
	i = 0;
	while (i < datas->nb_of_philo)
		pthread_mutex_destroy(&datas->forks[i++]);
	free(datas->philos);
	free(datas->forks);
	pthread_mutex_destroy(&datas->message_lock);
	pthread_mutex_destroy(&datas->permission_lock);
}

int	main(int argc, char *argv[])
{
	t_datas		datas;

	if (!init_datas(&datas, argc, argv))
		return (1);
	free_all(&datas);
	return (0);
}
