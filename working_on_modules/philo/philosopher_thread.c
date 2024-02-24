/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:13:03 by achappui          #+#    #+#             */
/*   Updated: 2024/02/24 15:56:40 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	thinkk(t_philo *philo)
{
	if (!message(philo, THINKING))
		return (0);
	if (philo->datas->nb_of_philo & 1)
		syncronize(philo);
	pthread_mutex_lock(philo->right_fork);
	if (!message(philo, FORKING))
	{
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	pthread_mutex_lock(philo->left_fork);
	if (!message(philo, FORKING))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	return (1);
}

static char	eatt(t_philo *philo)
{
	if (!message(philo, EATING))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	usleep(philo->datas->time_to_eat);
	pthread_mutex_lock(&philo->datas->global_lock);
	if (++philo->meal_counter == philo->datas->meal_limit)
		if (++philo->datas->finished_eating == philo->datas->nb_of_philo)
			philo->datas->end_status = 1;
	pthread_mutex_unlock(&philo->datas->global_lock);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}

static char	sleepp(t_philo *philo)
{
	if (!message(philo, SLEEPING))
		return (0);
	usleep(philo->datas->time_to_sleep);
	return (1);
}


void	*philosopher_thread(void *args)
{
	t_philo		*philo;
	pthread_t	counter;

	philo = (t_philo *)args;
	pthread_create(&counter, NULL, &counter_thread, philo);
	while (1)
	{
		if (!thinkk(philo))
			break ;
		if (!eatt(philo))
			break ;
		if (!sleepp(philo))
			break ;
	}
	pthread_join(counter, NULL);
	return (NULL);
}
