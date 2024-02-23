/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:40:28 by achappui          #+#    #+#             */
/*   Updated: 2024/02/22 13:50:35 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	think_routine(t_processdata *philo)
{
	sem_wait(philo->global_lock);
	sem_wait(philo->security);
	if (philo->dead)
		return (0);
	sem_post(philo->security);
	printf("\e[0m%u \e[1;37m%d \e[1;34mis thinking\n", \
	get_time(&philo->start_time), philo->id);	
	sem_post(philo->global_lock);
	usleep(TIME_TO_THINK);
	sem_wait(philo->fork_pairs);
	sem_wait(philo->global_lock);
	sem_wait(philo->security);
	if (philo->dead)
		return (0);
	sem_post(philo->security);
	printf("\e[0m%u \e[1;37m%d \e[1;33mhas taken a fork\n", \
	get_time(&philo->start_time), philo->id);
	printf("\e[0m%u \e[1;37m%d \e[1;33mhas taken a fork\n", \
	get_time(&philo->start_time), philo->id);
	sem_post(philo->global_lock);
	return (1);
}

static char	eat_routine(t_processdata *philo)
{
	sem_wait(philo->global_lock);
	sem_wait(philo->security);
	if (philo->dead)
		return (0);
	sem_post(philo->security);
	philo->last_meal = get_time(&philo->start_time);
	philo->meal_counter++;
	printf("\e[0m%u \e[1;37m%d \e[1;31mis eating\n", \
	get_time(&philo->start_time), philo->id);
	if (philo->meal_counter == philo->meal_limit)
		sem_post(philo->finished_eating);
	else
		sem_post(philo->global_lock);
	usleep(philo->time_to_eat);
	sem_post(philo->fork_pairs);
	return (1);
}

static char	sleep_routine(t_processdata *philo)
{
	sem_wait(philo->global_lock);
	sem_wait(philo->security);
	if (philo->dead)
		return (0);
	sem_post(philo->security);
	printf("\e[0m%u \e[1;37m%d \e[0;36mis sleeping\n", \
	get_time(&philo->start_time), philo->id);
	sem_post(philo->global_lock);
	usleep(philo->time_to_sleep);
	return (1);
}

void	philosopher_process(t_processdata *philo)
{
	pthread_t	counter;
	pthread_t	dead;

	pthread_create(&dead, NULL, &dead_thread, philo);
	pthread_create(&counter, NULL, &counter_thread, philo);
	while (1)
	{
		if (!think_routine(philo))
			break ;
		if (!eat_routine(philo))
			break ;
		if (!sleep_routine(philo))
			break ;
	}
	sem_post(philo->security);
	sem_post(philo->global_lock);
	sem_post(philo->finished_eating);
	pthread_join(dead, NULL);
	pthread_join(counter, NULL);
	sem_close(philo->end_signal);
	sem_close(philo->global_lock);
	sem_close(philo->fork_pairs);
	sem_close(philo->death_updated);
	sem_close(philo->security);
	sem_close(philo->finished_eating);
}