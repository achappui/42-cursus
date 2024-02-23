/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:55:55 by achappui          #+#    #+#             */
/*   Updated: 2024/02/09 08:17:05 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_processdata	datas;

	init_inputs(&datas, argc, argv);
	init_philo_infos(&datas);
	init_semaphores(&datas);
	gettimeofday(&datas.start_time, NULL);
	run_simulation(&datas);
	return (0);
}