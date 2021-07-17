#include "includes/philo.h"
//volatile int start;
int start;
//mutex для блокировки взятия вилок
pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER;

void	print_message(char *str, int id)
{
	long current_time;

	gettimeofday(&current_time, NULL);
	ft_putnbr_fd(current_time, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(id, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	// timestamp_in_ms X message
	//текущее время
	//id философа
	// сообщение (is eating, is sleeping, is thinking, has taken a fork, died)
}

void	*life_philo(void *arg)
{
	t_all *args;
	t_philo	*philo;
	t_table	*table;
	
	args = (t_all *)arg;
	table = args->table;
	philo = args->philo;
	// EAT
	while (!start)
		;
	//счетчик, чтобы лишний раз не вызывать lock/unlock (?)
	pthread_mutex_lock(&entry_point);
	pthread_mutex_lock(&table->forks[philo->left_fork]);
	print_message("has taken a fork", philo->id);
	//ft_usleep(10);
	pthread_mutex_lock(&table->forks[philo->right_fork]);
	print_message("has taken a fork", philo->id);
	philo->start_eat = get_time(args->input->time_to_eat);
	print_message("is eating", philo->id);
	pthread_mutex_unlock(&entry_point);
	ft_usleep(args->input->time_to_eat);
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
	pthread_mutex_unlock(&table->forks[philo->left_fork]);
	// ft_usleep(50);
	// print_message("is sleeping", philo->id);

	//pthread_mutex_lock(&message);
	//SLEEP
	//print_message(char *str, int nb)
	//pthread_mutex_unlock(&message);

	//pthread_mutex_lock(&message);
	//THINK
	//print_message(char *str, int nb)
	//pthread_mutex_unlock(&message);
}

void	*check_dead(void *arg)
{
	
}

void	pthread_exec(t_all *args, int count)
{
	int	i;

	i = -1;
	while (++i < count)
        pthread_create(&args[i].philo->pt, NULL, life_philo, &args[i]);
	start = 1;
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
	//раздавать вилки четным/нечетным
	init_philo(&philo[i], i, 0, i + 1);
	args = init_all_args(philo, &table, &input);
	start = 0;
	pthread_exec(args, input.num_of_philo);
	//отдельный поток на отслеживание смерти
	pthread_create(&args->death, NULL, check_dead, (void *)args);
	pthread_join(args->death, NULL);
	//free philo
	//free forks
	//free
	return (1);
}