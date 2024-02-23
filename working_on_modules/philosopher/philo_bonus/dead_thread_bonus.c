/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_thread_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:40:38 by achappui          #+#    #+#             */
/*   Updated: 2024/02/09 21:59:38 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*dead_thread(void *args)
{
	t_processdata	*philo;

	philo = (t_processdata *)args;
	sem_wait(philo->end_signal);
	philo->dead = 1;
	sem_post(philo->death_updated);
	sem_post(philo->death_updated);
	return (NULL);
}
