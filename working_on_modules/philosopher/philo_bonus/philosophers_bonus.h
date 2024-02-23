/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:34 by achappui          #+#    #+#             */
/*   Updated: 2024/02/09 19:19:36 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h> 

# define NO_MEAL_LIMIT	65536
# define TIME_TO_THINK	500

typedef struct s_processdata
{
	unsigned int	id;
	unsigned int	meal_counter;
	unsigned int	last_meal;
	unsigned int	nb_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	meal_limit;
	char			dead;
	sem_t			*fork_pairs;
	sem_t			*global_lock;
	sem_t			*end_signal;
	sem_t			*death_updated;
	sem_t			*security;
	sem_t			*finished_eating;
	struct timeval	start_time;
}	t_processdata;

void			run_simulation(t_processdata *datas);
void			*dead_thread(void *args);
void			init_semaphores(t_processdata *datas);
void			init_philo_infos(t_processdata *datas);
char			init_inputs(t_processdata *datas, int argc, char *argv[]);
void			*counter_thread(void *args);
unsigned int	get_time(struct timeval *start_time);
void			philosopher_process(t_processdata *philo);
int				ft_strlen(const char *s);
int				ft_uatoi(const char *str);
char			valid_ushort(const char *str);

#endif
