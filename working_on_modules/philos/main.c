/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:06:41 by achappui          #+#    #+#             */
/*   Updated: 2024/01/29 15:49:35 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long	get_millisec_diff()
{
	gettimeofday();
}

void	free_all(t_philo *philos, t_fork *forks, unsigned int last_fork)
{
	unsigned int	i;

	i = 0;
	if (forks)
	{
		while (i < last_fork)
			pthread_mutex_destroy(&forks[i++]);
		free(forks);
	}
	if (philos)
		free(philos);
}

void	*philo_routine(t_philo *args)
{
	while (args->datas.) //determiner la condition d'arret personnelle a chaque philosophes
	{
		while (args->inputs->start)
			;
		printf("%llu %u is thinking\n");
		pthread_mutex_lock(args->right_fork);
		printf("has taken a fork\n");
		pthread_mutex_lock(args->left_fork);
		printf("has taken a fork\n");
		printf("is eating\n");
		usleep(args->inputs->time_to_eat);
		pthread_mutex_unlock(args->right_fork);
		pthread_mutex_unlock(args->left_fork);
		printf("is sleeping\n");
		usleep(args->inputs->time_to_sleep); //verifier surplace la taille qu'on peut mettre dans usleep
	}
}


int main(int argc, char* argv[]) //pour gettime of day prendre en compte le cas particulier ou on arrive a minuit, ainsi le temps 2 serait plus petit que le temps 1
{
	t_inputs	inputs;
	t_philo		*philos;
	t_fork		*forks;
	long long	i;

	if (input_handler(&inputs, argc, argv) != OK)
		return (1);
	i = init_forks(&inputs, &forks);
	if (i != OK)
	{
		free_all(philos, forks, i);
		return (1);
	}
	i = init_philos(&inputs, &philos, forks);
	if (i != OK)
	{
		free_all(philos, forks, i);
		return (1);
	}
	inputs.start = 1;
	i = -1;
	while (++i < inputs.number_of_philosophers)
		pthread_join(philos[i].thread, NULL);
	free_all(philos, forks, inputs.number_of_philosophers);
    return (0);
}