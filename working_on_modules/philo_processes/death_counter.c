/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:45:20 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 20:21:56 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static unsigned long long	calcul_diff_timer(t_philo *philo)
{
	unsigned long long	new_timer;

	new_timer = \
	philo->time_to_die - (get_time(philo->st_ref) - philo->last_meal);
	if (new_timer > philo->time_to_die)
		new_timer = philo->time_to_die;
	return (new_timer);
}

void	philosopher_died(t_philo *philo)
{
	unsigned int	i;

	printf("%llu %d died\n", get_time(philo->st_ref), philo->id);
	i = 0;
	while (i++ < philo->philo_nb)
		sem_post(philo->end_locks_1);
	i = 0;
	while (i++ < philo->philo_nb)
		sem_wait(philo->end_locks_2);
}

void	*death_counter_thread(void *args)
{
	t_philo				*philo;
	unsigned int		saved_meal_counter;
	unsigned long long	timer;

	philo = (t_philo *)args;
	saved_meal_counter = 0;
	timer = philo->time_to_die;
	while (!philo->end_status && !philo->done_eating)
	{
		//printf("DEATHCOUNTER: STILL RUNNING\n");
		usleep(timer * 1000);
		sem_wait(philo->global_lock);
		if (!philo->end_status && !philo->done_eating && saved_meal_counter == philo->meal_counter)
			philosopher_died(philo);
		timer = calcul_diff_timer(philo);
		saved_meal_counter = philo->meal_counter;
		sem_post(philo->global_lock);
	}
	// if (philo->datas->nb_of_philo == 1) // TROUVER UNE SOLUTION
	// 	pthread_mutex_unlock(philo->left_fork);
	//printf("DEATHCOUNTER: FINISHED\n");
	return (NULL);
}