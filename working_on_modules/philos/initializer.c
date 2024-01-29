/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:13:20 by achappui          #+#    #+#             */
/*   Updated: 2024/01/29 13:45:03 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	swap_forks()
{
	
}

long long	init_forks(t_inputs *inputs, t_fork **forks)
{
	unsigned int	i;

	*forks = (t_fork *)malloc(inputs->number_of_philosophers * sizeof(t_fork)); //faut initialiser eat counter et tt
	if (!*forks)
	{
		write(2, "Malloc error !\n", 15);
		return (0);
	}
	i = -1;
	while (++i < inputs->number_of_philosophers)
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (i);
	return (OK);
}

long long	init_philos(t_inputs *inputs, t_philo **philos, t_fork *forks)
{
	unsigned int	i;

	*philos = (t_philo *)malloc(inputs->number_of_philosophers * sizeof(t_philo)); //faut initialiser eat counter et tt
	if (!*philos)
	{
		write(2, "Malloc error !\n", 15);
		return (0);
	}
	i = -1;
	while (++i < inputs->number_of_philosophers)
	{
		if (pthread_create(&philos[i]->thread, NULL, &philo_routine, &philos[i]) != 0)
			return (i);
		philos[i]->eat_counter = 0;
		philos[i]->inputs = inputs;
		philos[i]->right_fork = &forks[i];
		philos[i]->left_fork = &forks[inputs->number_of_philosophers + i - 1 % inputs->number_of_philosophers];
		if (i & 1)
			swap_forks();
	}
	return (OK);
}