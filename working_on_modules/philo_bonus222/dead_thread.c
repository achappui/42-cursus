/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:40:38 by achappui          #+#    #+#             */
/*   Updated: 2024/02/22 13:50:08 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dead_thread(void *args)
{
	t_processdata	*datas;

	datas = (t_processdata *)args;
	sem_wait(datas->end_signal);
	sem_wait(datas->security);
	datas->dead = 1;
	sem_post(datas->security);
	sem_post(datas->death_updated);
	sem_post(datas->death_updated);
	return (NULL);
}