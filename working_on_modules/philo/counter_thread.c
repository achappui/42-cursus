/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:02:42 by achappui          #+#    #+#             */
/*   Updated: 2024/02/11 19:56:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*counter_thread(void *args)
{
	t_philo			*philo;
	unsigned int	timer;

	philo = (t_philo *)args;
	timer = philo->datas->time_to_die;
	while (1)
	{
		usleep(timer * 1000);
		pthread_mutex_lock(&philo->datas->global_lock);
		if (philo->datas->end_status)
		{
			pthread_mutex_unlock(&philo->datas->global_lock);
			break ;
		}
		timer = get_time(&philo->datas->start_time) - philo->last_meal;
		if (timer > philo->datas->time_to_die)
		{
			printf("\e[0m%u \e[1;37m%d \e[0;31mdied\n", \
			get_time(&philo->datas->start_time), philo->id);
			philo->datas->end_status = 1;
			pthread_mutex_unlock(&philo->datas->global_lock);
			break ;
		}
		timer = philo->datas->time_to_die - timer;
		pthread_mutex_unlock(&philo->datas->global_lock);
	}
	if (philo->datas->nb_of_philo == 1) //pas correct de unlock la fork de qqn d'autre
		pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}