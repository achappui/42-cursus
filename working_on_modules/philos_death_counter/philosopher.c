/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:13:03 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 01:27:24 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static unsigned long long	get_time(struct timeval *start_time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - \
			(start_time->tv_sec * 1000 + start_time->tv_usec / 1000));
}

static unsigned long long	calcul_diff_timer(t_philo *philo)
{
	unsigned long long	new_timer;

	new_timer = philo->datas->time_to_die - \
	(get_time(&philo->datas->start_time) - philo->last_meal);
	if (new_timer > philo->datas->time_to_die)
		new_timer = philo->datas->time_to_die;
	return (new_timer);
}

static void	*death_routine(void *args)
{
	t_philo				*philo;
	unsigned int		saved_meal_counter;
	unsigned long long	timer;

	philo = (t_philo *)args;
	saved_meal_counter = 0;
	timer = philo->datas->time_to_die;
	while (!philo->datas->end_status && philo->still_eating)
	{
		usleep(timer * 1000);
		pthread_mutex_lock(&philo->datas->locker);
		if (!philo->datas->end_status && philo->still_eating && \
		saved_meal_counter == philo->meal_counter)
		{
			printf("%llu %d died\n", \
			get_time(&philo->datas->start_time), philo->id);
			philo->datas->end_status = 1;
		}
		timer = calcul_diff_timer(philo);
		saved_meal_counter = philo->meal_counter;
		pthread_mutex_unlock(&philo->datas->locker);
	}
	if (philo->datas->nb_of_philo == 1)
		pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

static void	action(t_philo *philo, char what)
{
	pthread_mutex_lock(&philo->datas->locker);
	if (!philo->datas->end_status && philo->still_eating)
	{
		if (what == TOOK_A_FORK)
			printf("%llu %d has taken a fork\n", \
			get_time(&philo->datas->start_time), philo->id);
		else if (what == THINK)
			printf("%llu %d is thinking\n", \
			get_time(&philo->datas->start_time), philo->id);
		else if (what == EAT)
		{
			philo->meal_counter++;
			philo->last_meal = get_time(&philo->datas->start_time);
			if (philo->meal_counter == philo->datas->meal_limit)
				philo->still_eating = 0;
			printf("%llu %d is eating\n", \
			get_time(&philo->datas->start_time), philo->id);
		}
		else if (what == SLEEP)
			printf("%llu %d is sleeping\n", \
			get_time(&philo->datas->start_time), philo->id);
	}
	pthread_mutex_unlock(&philo->datas->locker);
}

void	*philosopher_routine(void *args)
{
	t_philo		*philo;
	pthread_t	death_timer;

	philo = (t_philo *)args;
	pthread_create(&death_timer, NULL, &death_routine, philo);
	while (!philo->datas->end_status && philo->still_eating)
	{
		action(philo, THINK);
		pthread_mutex_lock(philo->right_fork);
		action(philo, TOOK_A_FORK);
		pthread_mutex_lock(philo->left_fork);
		action(philo, TOOK_A_FORK);
		action(philo, EAT);
		usleep(philo->datas->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		action(philo, SLEEP);
		usleep(philo->datas->time_to_sleep);
	}
	pthread_join(death_timer, NULL);
	return (NULL);
}
