/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:13:20 by achappui          #+#    #+#             */
/*   Updated: 2024/01/30 16:23:16 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	supervisor()
{
	int		start_time;
	void	*time_list_philo;

	
}

void	*philo_routine(void *voidargs)
{
	t_philo	*args;

	args = (t_philo *)voidargs;
	while (args->eat_counter != args->datas->max_meal_nb) //args->datas->no_meal_limit || 
	{
		check_death();
		write(1, "is thinking\n", 12);
		pthread_mutex_lock(args->right_fork);
		check_death();
		write(1, "has taken a fork\n", 17);
		pthread_mutex_lock(args->left_fork);
		check_death();
		write(1, "has taken a fork\n", 17);
		check_death();
		write(1, "is eating\n", 10);
		usleep(args->datas->eat_time);
		//reset_timer();
		args->eat_counter++;
		pthread_mutex_unlock(args->right_fork);
		pthread_mutex_unlock(args->left_fork);
		check_death();
		write(1, "is sleeping\n", 12);
		usleep(args->datas->sleep_time); //verifier surplace la taille qu'on peut mettre dans usleep
	}
	return (NULL);
}

long long	init_forks(t_datas *datas, t_fork **forks)
{
	int	i;

	*forks = (t_fork *)malloc(datas->nb_of_philo * sizeof(t_fork)); //faut initialiser eat counter et tt
	if (!*forks)
		return (0 * write(2, "Malloc error !\n", 15));
	i = -1;
	while (++i < datas->nb_of_philo)
		if (pthread_mutex_init(&(*forks)[i], NULL) != 0)
			return (i);
	return (OK);
}

long long	init_philos(t_datas *datas, t_philo **philos, t_fork *forks)
{
	int	i;

	*philos = (t_philo *)malloc(datas->nb_of_philo * sizeof(t_philo)); //faut initialiser eat counter et tt
	if (!*philos)
		return (0 * write(2, "Malloc error !\n", 15));
	i = 1;
	while (i < datas->nb_of_philo)
	{
		(*philos)[i].philo_id = i + 1;
		(*philos)[i].eat_counter = 0;
		(*philos)[i].datas = datas;
		(*philos)[i].right_fork = &forks[(datas->nb_of_philo + i - 1) % datas->nb_of_philo];
		(*philos)[i].left_fork = &forks[i];
		if (pthread_create(&(*philos)[i].philo_thread, NULL, &philo_routine, &(*philos)[i]) != 0) //mettre ces 2 blocs dans une fonction
			return (i);
		i += 2;
	}
	usleep(5000);
	i = 0;
	while (i < datas->nb_of_philo)
	{
		(*philos)[i].philo_id = i + 1;
		(*philos)[i].eat_counter = 0;
		(*philos)[i].datas = datas;
		(*philos)[i].right_fork = &forks[i];
		(*philos)[i].left_fork = &forks[(datas->nb_of_philo + i - 1) % datas->nb_of_philo];
		if (pthread_create(&(*philos)[i].philo_thread, NULL, &philo_routine, &(*philos)[i]) != 0)
			return (i);
		i += 2;
	}
	return (OK);
}

