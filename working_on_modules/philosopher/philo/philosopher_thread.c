/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:13:03 by achappui          #+#    #+#             */
/*   Updated: 2024/02/11 11:37:04 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	thinkk(t_philo *philo)
{
	if (!message(philo, THINKING))
		return (0);
	while (check_permission(philo) == 0)
	{
		//printf("WAITTING\n");
		usleep(1);
	}
	// printf("OUT %d\n", philo->id);
	pthread_mutex_lock(philo->right_fork);
	// printf("OUT 2 %d\n", philo->id);
	if (!message(philo, FORKING))
	{
		// printf("OUT %d\n", philo->id);
		pthread_mutex_unlock(philo->right_fork);
		update_permissions(philo);
		return (0);
	}
	// printf("OUT %d\n", philo->id);
	pthread_mutex_lock(philo->left_fork);
	// printf("OUT\n");
	if (!message(philo, FORKING))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		update_permissions(philo);
		return (0);
	}
	// printf("OUT\n");
	return (1);
}

char	eatt(t_philo *philo)
{
	if (!message(philo, EATING))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		update_permissions(philo);
		return (0);
	}
	usleep(philo->datas->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	update_permissions(philo);
	return (1);
}

char	sleepp(t_philo *philo)
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
	//printf("COMBIEN\n");
	pthread_join(counter, NULL);
	return (NULL);
}
