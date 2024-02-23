void	*philo_routine(void *voidargs)
{
	t_philo	*args;

	args = (t_philo *)voidargs;
	while (args->datas->no_meal_limit || (args->eat_counter != args->datas->max_meal_nb))
	{
		printf("is thinking\n");
		pthread_mutex_lock(args->right_fork);
		printf("has taken a fork\n");
		pthread_mutex_lock(args->left_fork);
		printf("has taken a fork\n");
		printf("is eating\n");
		usleep(args->datas->eat_time);
		args->eat_counter++;
		pthread_mutex_unlock(args->right_fork);
		pthread_mutex_unlock(args->left_fork);
		printf("is sleeping\n");
		usleep(args->datas->sleep_time); //verifier surplace la taille qu'on peut mettre dans usleep
	}
	return (NULL);
}

// static void	swap_forks(t_fork **fork1, t_fork **fork2)
// {
// 	t_fork	*tmp;

// 	tmp = *fork1;
// 	*fork1 = *fork2;
// 	*fork2 = tmp;
// }

// void	*philo_routine(t_philo *args)
// {
// 	while (args->datas->no_meal_limit || (args->eat_counter != args->datas->max_meal_nb))
// 	{
// 		write(1, "is thinking\n", 12);
// 		pthread_mutex_lock(args->right_fork);
// 		if ()
// 		write(1, "has taken a fork\n", 17);
// 		pthread_mutex_lock(args->left_fork);
// 		write(1, "has taken a fork\n", 17);
// 		write(1, "is eating\n", 10);
// 		usleep(args->datas->eat_time);
// 		args->eat_counter++;
// 		pthread_mutex_unlock(args->right_fork);
// 		pthread_mutex_unlock(args->left_fork);
// 		write(1, "is sleeping\n", 11);
// 		usleep(args->datas->sleep_time); //verifier surplace la taille qu'on peut mettre dans usleep
// 	}
// }
