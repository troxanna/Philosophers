#include "../includes/philo.h"


void	init_table(t_table *table, int count)
{
	int	i;

	table->forks = (mutex_t *)malloc(sizeof(mutex_t) * count);
	if (!table->forks)
		ft_error(1);
	i = -1;
	while (++i < count)
		pthread_mutex_init(&table->forks[i], NULL);
}

void	init_philo(t_philo **philo, int id, mutex_t *l_fork, mutex_t *r_fork)
{
	//t_philo	*philo;
	*philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		ft_error(1);
	(*philo)->id = id;
	(*philo)->left_fork = l_fork;
	(*philo)->right_fork = r_fork;
	(*philo)->start_eat = get_time(0);
	(*philo)->last_eat = get_time(0);
}

// void	init_table(t_table *table, int count)
// {
//     int	i;

// 	table->forks = (mutex_t *)malloc(sizeof(mutex_t) * count);
// 	if (!table->forks)
// 		ft_error(1);
// 	i = -1;
// 	while (++i < count)
// 		pthread_mutex_init(&table->forks[i], NULL);
// }

void	free_philo(t_philo **philo)
{
	int	i;

	i = -1;
	while (++i)
		free(philo[i]);
	free(philo);
}

t_input	init_input(int n_philo, int t_die, int t_eat, int t_sleep)
{
	t_input	input;

	input.num_of_philo = n_philo;
	input.time_to_die = t_die;
	input.time_to_eat = t_eat;
	input.time_to_sleep = t_sleep;
	input.count_eat = -1;
	return (input);
}

t_all	*init_all_args(t_philo **philo, t_input *input)
{
	t_all	*args;

	args = (t_all *)malloc(sizeof(t_all) * input->num_of_philo);

	// args->death = 0;
	// args->input;
	// args->philo = philo;
	// args->table = table;
	int	i;

	i = -1;
	while (++i < input->num_of_philo)
	{
		args[i].philo = philo[i];
		args[i].input = input;
		args[i].death = 0;
	}
	return (args);
}

