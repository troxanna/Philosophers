#include "includes/philo.h"

//mutex для блокировки взятия вилок
pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER;

void	*life_philo(void *arg)
{
	t_all *args;
	t_philo	*philo;
	t_table	*table;
	
	args = (t_all *)arg;
	table = args->table;
	philo = args->philo;
	// EAT
	pthread_mutex_lock(&entry_point);
	pthread_mutex_lock(&table->forks[philo->left_fork]);
	ft_usleep(30);
	pthread_mutex_lock(&table->forks[philo->right_fork]);
	pthread_mutex_unlock(&entry_point);
	ft_putstr_fd("philo eat\n", 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(philo->left_fork, 1);
	ft_putnbr_fd(philo->right_fork, 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
	pthread_mutex_unlock(&table->forks[philo->left_fork]);
}

void	pthread_exec(t_all *args, int count)
{
	int	i;

	i = -1;
	while (++i < count)
        pthread_create(&args[i].philo->pt, NULL, life_philo, &args[i]);
	i = -1;
	while (++i < count)
        pthread_join(args[i].philo->pt, NULL);
}

int		main(int argc, char **argv)
{
	int	c_eat;
	t_input	input;
	t_all	*args;
	t_table table;
	t_philo **philo;
	int i;

	if (argc < 5)
		ft_error(2);
	input = init_input(ft_atoi(argv[1]), ft_atoi(argv[2]),
				ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc == 6)
		input.count_eat = ft_atoi(argv[5]);
	philo = (t_philo **)malloc(sizeof(t_philo *) * (input.num_of_philo + 1));
	philo[input.num_of_philo] = NULL;
	i = -1;
	init_table(&table, input.num_of_philo);
	while (++i < input.num_of_philo - 1)
		init_philo(&philo[i], i, i + 1, i + 1);
	//обработать вилки для последнего философа
	init_philo(&philo[i], i, 0, i + 1);
	args = init_all_args(philo, &table, &input);
	pthread_exec(args, input.num_of_philo);
	// i = -1;
	// while (philo[++i])
	// {
	// 	ft_putnbr_fd(philo[i]->id, 1);
	// 	ft_putchar_fd('\n', 1);
	// 	ft_putnbr_fd(philo[i]->left_fork, 1);
	// 	ft_putnbr_fd(philo[i]->right_fork, 1);
	// 	ft_putchar_fd('\n', 1);
	// 	ft_putchar_fd('\n', 1);
	// }

	//free philo
	//free forks
	//free
	return (1);
}