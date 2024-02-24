/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:07:36 by achappui          #+#    #+#             */
/*   Updated: 2024/02/24 15:53:50 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	syncronize(t_philo *philo)
{
	if (philo->sync == -1)
	{
		if (philo->id == 1)
			philo->sync = 1;
		else
		{
			philo->sync = philo->id / 2;
			if (!(philo->id & 1))
				usleep(philo->datas->time_to_eat);
			else
				return ;
		}
	}
	if (philo->sync == 1)
	{
		philo->sync = philo->datas->nb_of_philo / 2;
		usleep(philo->datas->time_to_eat);
	}
	else
		philo->sync--;
}

char	message(t_philo *philo, char message)
{
	unsigned int	time;

	time = get_time(&philo->datas->start_time);
	pthread_mutex_lock(&philo->datas->global_lock);
	if (philo->datas->end_status)
	{
		pthread_mutex_unlock(&philo->datas->global_lock);
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
	}
	else if (message == SLEEPING)
		printf("\e[0m%u \e[1;37m%d \e[0;36mis sleeping\n", time, philo->id);
	pthread_mutex_unlock(&philo->datas->global_lock);
	return (1);
}