/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:34 by achappui          #+#    #+#             */
/*   Updated: 2024/01/30 11:37:17 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>

# define OK	-15

typedef pthread_mutex_t	t_fork;

typedef struct s_datas
{
	int	nb_of_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	max_meal_nb;
	int	no_meal_limit;
}	t_datas;

typedef struct s_philo
{
	int			philo_id;
	int			eat_counter;
	t_fork		*right_fork;
	t_fork		*left_fork;
	t_datas		*datas;
	pthread_t	philo_thread;
}	t_philo;

char		input_handler(t_datas *datas, int argc, char *argv[]);
long long	init_forks(t_datas *datas, t_fork **forks);
long long	init_philos(t_datas *datas, t_philo **philos, t_fork *forks);

#endif