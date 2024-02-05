/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:38:42 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 20:21:45 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long	get_time(struct timeval *start_time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - \
			(start_time->tv_sec * 1000 + start_time->tv_usec / 1000);
}

static void	action(t_philo *philo, char what)
{
	sem_wait(philo->global_lock);
	if (!philo->end_status && !philo->done_eating)
	{
		if (what == TOOK_TWO_FORKS)
			printf("%llu %d has taken a fork\n%llu %d has taken a fork\n", \
			get_time(philo->st_ref), philo->id, get_time(philo->st_ref), philo->id);
		else if (what == IS_THINKING)
			printf("%llu %d is thinking\n", get_time(philo->st_ref), philo->id);
		else if (what == IS_EATING)
		{
			philo->meal_counter++;
			if (philo->meal_counter == philo->meal_limit)
				philo->done_eating = 1;
			philo->last_meal = get_time(philo->st_ref);	
			printf("%llu %d is eating\n", get_time(philo->st_ref), philo->id);
		}
		else if (what == IS_SLEEPING)
			printf("%llu %d is sleeping\n", get_time(philo->st_ref), philo->id);
	}
	sem_post(philo->global_lock);
}

void	philosopher(t_philo *philo)
{
	pthread_t	death_counter;
	pthread_t	end_checker;

	pthread_create(&end_checker, NULL, &end_checker_thread, philo);
	pthread_create(&death_counter, NULL, &death_counter_thread, philo);
	while (!philo->end_status && !philo->done_eating)
	{
		//printf("Counter: %u Done_eating: %u Meal_limit %u\n", philo->meal_counter, philo->done_eating, philo->meal_limit);
		action(philo, IS_THINKING);
		usleep(ADVANTAGE_GIVER);
		sem_wait(philo->fork_pairs);
		action(philo, TOOK_TWO_FORKS);
		action(philo, IS_EATING);
		usleep(philo->time_to_eat);
		sem_post(philo->fork_pairs);
		action(philo, IS_SLEEPING);
		usleep(philo->time_to_sleep);
		
	}
	pthread_join(death_counter, NULL);
	sem_post(philo->finished_eating);
	//printf("FINISHED EATING\n");
	sem_close(philo->end_locks_1);
	sem_close(philo->end_locks_2);
	sem_close(philo->fork_pairs);
	sem_close(philo->global_lock);
	pthread_join(end_checker, NULL);
}