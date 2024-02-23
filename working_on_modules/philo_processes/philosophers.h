/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:04:34 by achappui          #+#    #+#             */
/*   Updated: 2024/02/05 19:15:14 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <sys/wait.h>
# include <time.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h> 
# include <wait.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/time.h>

# define NO_MEAL_LIMIT		65536
# define ADVANTAGE_GIVER	500
# define IS_THINKING		0
# define TOOK_TWO_FORKS		1
# define IS_EATING			2
# define IS_SLEEPING		3

typedef char t_bool;

typedef struct s_philo
{
	unsigned int	philo_nb;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	meal_limit;
	sem_t			*fork_pairs;
	sem_t			*global_lock;
	sem_t			*end_locks_1;
	sem_t			*end_locks_2;
	sem_t			*finished_eating;
	unsigned int	id;
	unsigned int	meal_counter;
	unsigned int	last_meal;
	t_bool			end_status;
	t_bool			done_eating;
	struct timeval	*st_ref;
}	t_philo;

void				philosopher(t_philo *philo);
void				*end_checker_thread(void *args);
void				*death_counter_thread(void *args);

void				init_inputs(t_philo *philo, int argc, char *argv[]);
void				init_philosopher_state(t_philo *philo);
void				init_semaphores(t_philo *philo);

unsigned long long	get_time(struct timeval *start_time);
int					ft_strlen(const char *s);
int					ft_uatoi(const char *str);
char				valid_ushort(const char *str);
void				error_input(char err_no);

#endif
