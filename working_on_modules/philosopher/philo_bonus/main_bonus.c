/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:55:55 by achappui          #+#    #+#             */
/*   Updated: 2024/02/09 21:55:02 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char *argv[])
{
	t_processdata	datas;

	if (!init_inputs(&datas, argc, argv))
		return (1);
	init_philo_infos(&datas);
	init_semaphores(&datas);
	gettimeofday(&datas.start_time, NULL);
	run_simulation(&datas);
	return (0);
}
