/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:34 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 01:05:41 by achappui         ###   ########.fr       */
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

# define HALF_ADVANTAGE 500
# define NO_MEAL_LIMIT	65536
# define EVEN			0
# define ODD			1
# define THINK			0
# define TOOK_A_FORK	1
# define EAT			2
# define SLEEP			3

typedef pthread_mutex_t	t_fork;
typedef char			t_bool;

typedef struct s_datas
{
	unsigned int		nb_of_philo;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		meal_limit;
	t_bool				end_status;
	struct timeval		start_time;
	pthread_mutex_t		locker;
}	t_datas;

typedef struct s_philo
{
	unsigned int		id;
	unsigned int		meal_counter;
	unsigned long long	last_meal;
	t_bool				still_eating;
	t_fork				*right_fork;
	t_fork				*left_fork;
	t_datas				*datas;
	pthread_t			philo_thread;
}	t_philo;

char	input_handler(t_datas *datas, int argc, char *argv[]);
void	init_forks(t_datas *datas, t_fork **forks);
void	run_philos(t_datas *datas, t_philo **philos, t_fork *forks);
void	*philosopher_routine(void *voidargs);

void	free_forks_to_n(t_fork *forks, int last_fork);
void	free_odd(t_philo *philos, int last);
void	free_even(t_philo *philos, int last);
#endif