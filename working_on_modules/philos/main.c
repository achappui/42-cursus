/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:06:41 by achappui          #+#    #+#             */
/*   Updated: 2024/01/30 13:37:47 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// unsigned long long	get_millisec_diff()
// {
// 	gettimeofday();
// }

// void	*philo_routine(t_philo *args)
// {
// 	while (args->datas.) //determiner la condition d'arret personnelle a chaque philosophes
// 	{
// 		while (args->datas->start)
// 			;
// 		printf("%llu %u is thinking\n");
// 		pthread_mutex_lock(args->right_fork);
// 		printf("has taken a fork\n");
// 		pthread_mutex_lock(args->left_fork);
// 		printf("has taken a fork\n");
// 		printf("is eating\n");
// 		usleep(args->datas->time_to_eat);
// 		pthread_mutex_unlock(args->right_fork);
// 		pthread_mutex_unlock(args->left_fork);
// 		printf("is sleeping\n");
// 		usleep(args->datas->time_to_sleep); //verifier surplace la taille qu'on peut mettre dans usleep
// 	}
// }

void	end_program(t_datas *datas, t_philo *philos, t_fork *forks, int last_fork)
{
	int	i;

	if (philos)
	{
		i = -1;
		while (++i < datas->nb_of_philo)
			pthread_join(philos[i].philo_thread, NULL);
		free(philos);
	}
	if (forks)
	{
		i = -1;
		while (++i < last_fork)
			pthread_mutex_destroy(&forks[i]);
		free(forks);
	}
}

int main(int argc, char* argv[]) //pour gettime of day prendre en compte le cas particulier ou on arrive a minuit, ainsi le temps 2 serait plus petit que le temps 1
{
	t_datas		datas;
	t_philo		*philos;
	t_fork		*forks;
	long long	i;

	if (input_handler(&datas, argc, argv) != OK) //revoir comment on peut simplifier le end of proramm
		return (1);
	i = init_forks(&datas, &forks);
	if (i != OK)
	{
		end_program(&datas, philos, forks, i);
		return (1);
	}
	i = init_philos(&datas, &philos, forks);
	if (i != OK)
	{
		end_program(&datas, philos, forks, i);
		return (1);
	}
	end_program(&datas, philos, forks, datas.nb_of_philo);
    return (0);
}