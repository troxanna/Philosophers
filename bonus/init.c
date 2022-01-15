#include "philo_bonus.h"

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

void	init_sem(sem_t **sem, int count)
{
	sem_t	*sem_print;
	sem_t	*sem_forks;
	sem_t	*sem_dead;

	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("dead_philo");

	if ((sem_forks = sem_open("forks", O_CREAT, 0777, count)) == SEM_FAILED)
		ft_error(1);
	if ((sem_print = sem_open("print", O_CREAT, 0777, 1)) == SEM_FAILED)
		ft_error(1);
	if ((sem_dead = sem_open("dead_philo", O_CREAT, 0777, 1)) == SEM_FAILED)
		ft_error(1);
	sem[0] = sem_forks;
	sem[1] = sem_print;
	sem[2] = sem_dead;
}

t_philo	*init(char **argv, int argc)
{
	t_input *input_data;
	t_philo	*philo;
	sem_t	**sem;
	//sem_t	*sem_print;
	int	i;

	//разобраться, почему делаем unlink	
	// sem_unlink("forks");
	// sem_unlink("print");
	// sem_unlink("dead_philo");
	input_data = init_input(argv, argc);
	philo = (t_philo *)malloc(sizeof(t_philo) * input_data->num_of_philo);
	sem = (sem_t **)malloc(sizeof(sem_t *) * 3);
	init_sem(sem, input_data->num_of_philo);
	if (!philo)
		ft_error(1);
	i = -1;
	while (++i < input_data->num_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].time_last_eat = get_time(0);
		philo[i].current_count_eat = 0;
		philo[i].input = input_data;
		philo[i].sem = sem;
		philo[i].time_start = get_time(0);
	}
	return (philo);
}