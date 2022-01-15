#include "philo.h"

t_input	*init_input(char **argv, int argc)
{
	t_input *data;

	data = (t_input *)malloc(sizeof(t_input));
	if (!data)
		ft_error(1);
	data->num_of_philo = ft_atoi(argv[1]);
	data->end = 0;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_count_eat = ft_atoi(argv[5]);
	else
		data->max_count_eat = -1;
	return (data);
}

//init_philo
void	init_philo(t_philo *philo, int id, size_t l_fork, size_t r_fork)
{
	philo->id = id;
	philo->left_fork = l_fork;
	philo->right_fork = r_fork;

}

t_philo	*init(char **argv, int argc)
{
	t_input *input_data;
	mutex_t	*forks;
	mutex_t	*message;
	t_philo	*philo;
	int	i;
	
	input_data = init_input(argv, argc);
	forks = (mutex_t *)malloc(sizeof(mutex_t) * input_data->num_of_philo);
	philo = (t_philo *)malloc(sizeof(t_philo) * input_data->num_of_philo);
	message = (mutex_t *)malloc(sizeof(mutex_t));
	
	if (!forks || !philo || !message)
		ft_error(1);
	i = -1;
	if (pthread_mutex_init(message, NULL))
			ft_error(4);
	while (++i < input_data->num_of_philo)
		if (pthread_mutex_init(&(forks[i]), NULL))
			ft_error(4);
	i = -1;
	while (++i < input_data->num_of_philo)
	{
		if (i == 0)
			init_philo(&philo[i], i + 1, i, input_data->num_of_philo - 1);
		else
			init_philo(&philo[i], i + 1, i, i - 1);	
		philo[i].forks = forks;
		philo[i].time_last_eat = get_time(0);
		philo[i].current_count_eat = 0;
		philo[i].message = message;
		philo[i].input = input_data;
	}
	return (philo);
}