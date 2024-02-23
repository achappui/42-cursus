/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:34 by achappui          #+#    #+#             */
/*   Updated: 2024/02/11 11:27:08 by achappui         ###   ########.fr       */
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

typedef char	t_bool;

typedef struct s_datas
{
	unsigned int		nb_of_philo;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		meal_limit;
	unsigned int		limit_reached;
	unsigned int		finished_eating;
	unsigned int		permission_index;
	t_bool				end_routine;
	pthread_mutex_t		permission_lock;
	pthread_mutex_t		message_lock;
	struct s_philo		*philos;
	pthread_mutex_t		*forks;
	struct timeval		start_time;
}	t_datas;

typedef struct s_philo
{
	unsigned int		id;
	unsigned int		meal_counter;
	unsigned int		last_meal;
	t_bool				eating_permission;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	struct s_datas		*datas;
	pthread_t			thread;
}	t_philo;


char			init_datas(t_datas *datas, int argc, char *argv[]);
void			*counter_thread(void *args);
void			*philosopher_thread(void *args);
char			message(t_philo *philo, char message);
void			update_permissions(t_philo *philo);
char			check_permission(t_philo *philo);

unsigned int	get_time(struct timeval *start_time);
char			valid_ushort(const char *str);
int				ft_uatoi(const char *str);
int				ft_strlen(const char *s);

#endif