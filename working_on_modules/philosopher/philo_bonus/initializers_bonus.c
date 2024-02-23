/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 06:03:54 by achappui          #+#    #+#             */
/*   Updated: 2024/02/09 22:26:26 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

char	init_inputs(t_processdata *datas, int argc, char *argv[])
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
		return (0 * write(1, "ERROR: 1 <= nb_of_philo <= 200 \n", 32));
	datas->time_to_die = ft_uatoi(argv[2]);
	datas->time_to_eat = ft_uatoi(argv[3]) * 1000;
	datas->time_to_sleep = ft_uatoi(argv[4]) * 1000;
	if (argc == 6)
	{
		datas->meal_limit = ft_uatoi(argv[5]);
		if (datas->meal_limit == 0)
			return (0 * write(1, "ERROR: 1 <= meal_limit \n", 24));
	}
	else
		datas->meal_limit = NO_MEAL_LIMIT;
	return (1);
}

void	init_philo_infos(t_processdata *datas)
{
	datas->dead = 0;
	datas->id = 0;
	datas->last_meal = 0;
	datas->meal_counter = 0;
}

void	init_semaphores(t_processdata *datas)
{
	sem_unlink("fork_pairs");
	sem_unlink("global_lock");
	sem_unlink("end_signal");
	sem_unlink("death_updated");
	sem_unlink("finished_eating");
	datas->fork_pairs = \
	sem_open("fork_pairs", O_CREAT | O_EXCL, 0777, datas->nb_of_philo / 2);
	datas->global_lock = \
	sem_open("global_lock", O_CREAT | O_EXCL, 0777, 1);
	datas->end_signal = \
	sem_open("end_signal", O_CREAT | O_EXCL, 0777, 0);
	datas->death_updated = \
	sem_open("death_updated", O_CREAT | O_EXCL, 0777, 0);
	datas->finished_eating = \
	sem_open("finished_eating", O_CREAT | O_EXCL, 0777, 0);
}
