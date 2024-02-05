/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:30:28 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 01:06:17 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(t_datas *datas, t_fork **forks)
{
	unsigned int	i;

	*forks = (t_fork *)malloc(datas->nb_of_philo * sizeof(t_fork));
	i = -1;
	while (++i < datas->nb_of_philo)
		pthread_mutex_init(&(*forks)[i], NULL);
}
