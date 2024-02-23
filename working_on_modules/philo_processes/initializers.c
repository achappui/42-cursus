/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:49:04 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 20:20:55 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_inputs(t_philo *philo, int argc, char *argv[])
{
	int	i;

	if (argc != 5 && argc != 6)
		error_input(1);
	i = 0;
	while (++i < argc)
		if (!valid_ushort(argv[i]))
			error_input(2);
	philo->philo_nb = ft_uatoi(argv[1]);
	if (philo->philo_nb > 1000)
		error_input(3);
	else if (philo->philo_nb == 0)
		error_input(4);
	philo->time_to_die = ft_uatoi(argv[2]);
	philo->time_to_eat = ft_uatoi(argv[3]) * 1000;
	philo->time_to_sleep = ft_uatoi(argv[4]) * 1000;
	if (argc == 6)
		philo->meal_limit = ft_uatoi(argv[5]);
	else
		philo->meal_limit = NO_MEAL_LIMIT;
}

void	init_philosopher_state(t_philo *philo)
{
	philo->end_status = 0;
	philo->id = 0;
	philo->last_meal = 0;
	philo->meal_counter = 0;
	philo->done_eating = 0;
}


void init_semaphores(t_philo *philo) {
    unsigned int i;

	sem_unlink("end_locks_1");
	sem_unlink("end_locks_2");
	sem_unlink("fork_pairs");
	sem_unlink("global_lock");
	sem_unlink("finished_eating");
    philo->finished_eating = sem_open("finished_eating", O_CREAT | O_EXCL, 0777, philo->philo_nb);
    philo->end_locks_1 = sem_open("end_locks_1", O_CREAT | O_EXCL, 0777, philo->philo_nb);
    philo->end_locks_2 = sem_open("end_locks_2", O_CREAT | O_EXCL, 0777, philo->philo_nb);
    philo->global_lock = sem_open("global_lock", O_CREAT | O_EXCL, 0777, 1);
    philo->fork_pairs = sem_open("fork_pairs", O_CREAT | O_EXCL, 0777, philo->philo_nb / 2);
    i = 0;
    while (i < philo->philo_nb) {
        sem_wait(philo->finished_eating);
        sem_wait(philo->end_locks_1);
        sem_wait(philo->end_locks_2);
        i++;
    }
}

// void	init_semaphores(t_philo *philo)
// {
// 	unsigned int	i;

// 	philo->finished_eating = sem_open("finished_eating", 
// 	O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, philo->philo_nb);
// 	philo->end_locks_1 = sem_open("end_locks_1", 
// 	O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, philo->philo_nb);
// 	philo->end_locks_2 = sem_open("end_locks_2", 
// 	O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, philo->philo_nb);
// 	philo->global_lock = sem_open("global_lock", 
// 	O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
// 	philo->fork_pairs = sem_open("fork_pairs", 
// 	O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, philo->philo_nb / 2);
// 	i = 0;
// 	while (i < philo->philo_nb)
// 	{
// 		sem_wait(philo->finished_eating);
// 		sem_wait(philo->end_locks_1);
// 		sem_wait(philo->end_locks_2);
// 		i++;
// 	}
// }