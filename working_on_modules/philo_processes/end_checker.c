/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:44:40 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 20:22:00 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*end_checker_thread(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	//printf("END_CHECKER STARTED\n");
	sem_wait(philo->end_locks_1);
	philo->end_status = 1;
	//printf("END_CHECKER IN\n");
	sem_post(philo->end_locks_2);
	//printf("END_CHECKER FINISHED\n");
	return (NULL);
}
