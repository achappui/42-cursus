/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 08:17:08 by achappui          #+#    #+#             */
/*   Updated: 2024/02/09 22:26:17 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	wait_and_free(t_processdata *datas)
{
	unsigned int	i;

	i = 0;
	while (i++ < datas->nb_of_philo)
		waitpid(-1, NULL, 0);
	sem_close(datas->end_signal);
	sem_close(datas->global_lock);
	sem_close(datas->fork_pairs);
	sem_close(datas->finished_eating);
	sem_unlink("fork_pairs");
	sem_unlink("global_lock");
	sem_unlink("end_signal");
	sem_unlink("death_updated");
	sem_unlink("finished_eating");
}

static void	end_simulation(t_processdata *datas)
{
	unsigned int	i;

	sem_wait(datas->finished_eating);
	i = 1;
	while (i++ < datas->nb_of_philo)
	{
		sem_post(datas->global_lock);
		sem_wait(datas->finished_eating);
	}
	i = 0;
	while (i++ < datas->nb_of_philo)
		sem_post(datas->end_signal);
	i = 0;
	while (i++ < datas->nb_of_philo)
		sem_wait(datas->death_updated);
	sem_post(datas->global_lock);
	wait_and_free(datas);
}

void	run_simulation(t_processdata *datas)
{
	unsigned int	i;
	pid_t			childpid;

	childpid = 1;
	i = 0;
	while (i++ < datas->nb_of_philo && childpid != 0)
	{
		datas->id = i;
		childpid = fork();
	}
	if (childpid == 0)
		philosopher_process(datas);
	else
		end_simulation(datas);
}
