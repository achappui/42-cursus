/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:28:01 by achappui          #+#    #+#             */
/*   Updated: 2024/02/11 11:35:17 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	check_permission(t_philo *philo)
{
	// printf("hey there\n");
	pthread_mutex_lock(&philo->datas->permission_lock);
	if (philo->eating_permission == 1)
	{
		pthread_mutex_unlock(&philo->datas->permission_lock); //faire prendre des fourchette
		return (1);
	}
	pthread_mutex_unlock(&philo->datas->permission_lock);
	return (0);
}

void	update_permissions(t_philo *philo)
{
	unsigned int	i;
	unsigned int	start;

	// printf("HEY here");
	pthread_mutex_lock(&philo->datas->permission_lock);
	philo->eating_permission = 0;
	philo->datas->finished_eating++;
	if (philo->datas->finished_eating == philo->datas->nb_of_philo / 2)
	{
		philo->datas->permission_index = \
		(philo->datas->permission_index + 1) % philo->datas->nb_of_philo;
		philo->datas->finished_eating = 0;
		start = philo->datas->permission_index;
		i = 0;
		while (i++ < philo->datas->nb_of_philo / 2)
		{
			philo->datas->philos[start].eating_permission = 1;
			start = (start + 2) % philo->datas->nb_of_philo;
		}
	}
	pthread_mutex_unlock(&philo->datas->permission_lock);
}

char	message(t_philo *philo, char message)
{
	unsigned int	time;

	time = get_time(&philo->datas->start_time);
	//printf("STUCK %d\n", philo->id);
	pthread_mutex_lock(&philo->datas->message_lock);
	if (philo->datas->end_routine)
	{
		pthread_mutex_unlock(&philo->datas->message_lock);
		return (0);
	}
	else if (message == THINKING)
		printf("\e[0m%u \e[1;37m%d \e[1;34mis thinking\n", time, philo->id);
	else if (message == FORKING)
		printf("\e[0m%u \e[1;37m%d \e[1;33mhas taken a fork\n", time, philo->id);
	else if (message == EATING)
	{
		printf("\e[0m%u \e[1;37m%d \e[1;31mis eating\n", time, philo->id);
		philo->last_meal = time;
		if (++philo->meal_counter == philo->datas->meal_limit)
			if (++philo->datas->limit_reached == philo->datas->nb_of_philo)
				philo->datas->end_routine = 1;
	}
	else if (message == SLEEPING)
		printf("\e[0m%u \e[1;37m%d \e[0;36mis sleeping\n", time, philo->id);
	pthread_mutex_unlock(&philo->datas->message_lock);
	return (1);
}
