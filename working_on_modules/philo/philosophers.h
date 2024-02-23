/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:34 by achappui          #+#    #+#             */
/*   Updated: 2024/02/11 17:24:34 by achappui         ###   ########.fr       */
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

# define NO_MEAL_LIMIT	65536
# define THINKING		0
# define FORKING		1
# define EATING			2
# define SLEEPING		3

typedef pthread_mutex_t	t_fork;
typedef pthread_mutex_t	t_lock;
typedef char			t_bool;

typedef struct s_datas
{
	unsigned int		nb_of_philo;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		meal_limit;
	unsigned int		finished_eating;
	t_bool				end_status;
	t_lock				global_lock;
	struct timeval		start_time;
}	t_datas;

typedef struct s_philo
{
	unsigned int		id;
	unsigned int		meal_counter;
	unsigned int		last_meal;
	int					sync;
	t_fork				*right_fork;
	t_fork				*left_fork;
	t_datas				*datas;
	pthread_t			philo_thread;
}	t_philo;

void			syncronize(t_philo *philo);
char			message(t_philo *philo, char message);
void			*counter_thread(void *args);
void			*philosopher_thread(void *args);
char			init_datas(t_datas *datas, int argc, char *argv[]);
char			init_forks(t_datas *datas, t_fork **forks);
char			invite_philosophers(t_datas *datas, t_philo **philos, t_fork *forks);
unsigned int	get_time(struct timeval *start_time);
char			valid_ushort(const char *str);
int				ft_uatoi(const char *str);

#endif