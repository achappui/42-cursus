/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:13:29 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 20:32:18 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	run_simulation(t_philo *philo, pid_t *pid)
{
	unsigned int	i;

	*pid = 1;
	i = 0;
	while (i < philo->philo_nb && *pid != 0)
	{
		philo->id = i + 1;
		*pid = fork();
		i++;
	}
	if (*pid == 0)
		philosopher(philo);
}

void	end_simulation(t_philo *philo)
{
	unsigned int	finished_process;
	unsigned int	finished_eating;
	unsigned int	end_unlock;
	int				status;

	finished_eating = 0;
	while (finished_eating++ < philo->philo_nb)
	{
		//printf("Waiting_FINISED EATING\n");
		sem_wait(philo->finished_eating);
	}
	//printf("THEY FINISHED EATING\n");
	end_unlock = 0;
	while (end_unlock++ < philo->philo_nb)
		sem_post(philo->end_locks_1);
	status = 0;
	finished_process = 0;
	while (finished_process++ < philo->philo_nb)
	{
		//printf("Waiting_PID\n");
		waitpid(-1, &status, 0);
	}
	sem_close(philo->end_locks_1);
	sem_close(philo->end_locks_2);
	sem_close(philo->fork_pairs);
	sem_close(philo->global_lock);
	sem_close(philo->finished_eating);
	sem_unlink("end_locks_1");
	sem_unlink("end_locks_2");
	sem_unlink("fork_pairs");
	sem_unlink("global_lock");
	sem_unlink("finished_eating");
}

int	main(int argc, char *argv[])
{
	struct timeval	start_time;
	t_philo			philo;
	pid_t			pid;

	init_inputs(&philo, argc, argv);
	init_semaphores(&philo);
	init_philosopher_state(&philo);
	philo.st_ref = &start_time;
	gettimeofday(&start_time, NULL);
	run_simulation(&philo, &pid);
	if (pid != 0)
		end_simulation(&philo);
	return (0);
}
