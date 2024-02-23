/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_thread_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:38:57 by achappui          #+#    #+#             */
/*   Updated: 2024/02/09 22:32:03 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static char	simulation_killed(t_processdata *philo)
{
	unsigned int	i;

	printf("\e[0m%u \e[1;37m%d \e[0;31mdied\n", \
	get_time(&philo->start_time), philo->id);
	//sem_wait(philo->global_lock);
	sleep(3);
	i = 0;
	while (i++ < philo->nb_of_philo)
		sem_post(philo->end_signal);
	i = 0;
	while (i++ < philo->nb_of_philo)
		sem_wait(philo->death_updated);
	return (1);
}

void	*counter_thread(void *args)
{
	t_processdata	*philo;
	unsigned int	timer;

	philo = (t_processdata *)args;
	timer = philo->time_to_die;
	while (1)
	{
		usleep(timer * 1000);
		sem_wait(philo->global_lock);
		if (philo->dead)
			break ;
		sleep(3);
		timer = get_time(&philo->start_time) - philo->last_meal;
		if (timer > philo->time_to_die && simulation_killed(philo))
			break ;
		timer = philo->time_to_die - timer;
		sem_post(philo->global_lock);
	}
	sem_post(philo->global_lock);
	if (philo->nb_of_philo == 1)
		sem_post(philo->fork_pairs);
	return (NULL);
}
