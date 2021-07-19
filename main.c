#include "includes/philo.h"
//volatile int start;
int start;
//mutex для блокировки взятия вилок
pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dead = PTHREAD_MUTEX_INITIALIZER;



void	print_message(char *str, t_philo *philo)
{
	long current_time;

	//pthread_mutex_lock(&entry_point);
	current_time = get_time(philo->start_eat);
	ft_putnbr_fd(current_time, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	//pthread_mutex_unlock(&entry_point);
	// timestamp_in_ms X message
	//текущее время
	//id философа
	// сообщение (is eating, is sleeping, is thinking, has taken a fork, died)
}

void	philo_eat(t_all *arg)
{
	//сделать, чтобы ели только четные/нечетные философы
	pthread_mutex_lock(&entry_point);
	pthread_mutex_lock(arg->philo->left_fork);
	print_message("has taken a fork", arg->philo);
	pthread_mutex_lock(arg->philo->right_fork);
	print_message("has taken a fork", arg->philo);
	pthread_mutex_unlock(&entry_point);
	pthread_mutex_lock(&entry_point);
	print_message("is eating", arg->philo);
	arg->philo->last_eat = get_time(0);
	pthread_mutex_unlock(&entry_point);
	ft_usleep(arg->input->time_to_eat);
	pthread_mutex_unlock(arg->philo->left_fork);
	pthread_mutex_unlock(arg->philo->right_fork);
}

void	*life_philo(void *arg)
{
	t_all *args;
	t_philo	*philo;
	
	args = (t_all *)arg;
	philo = args->philo;
	while (!start)
		;
	while (start == 1)
	{
		pthread_mutex_lock(&entry_point);
		if (get_time(0) - philo->last_eat >= args->input->time_to_die)
		{
			start = 2;
			print_message("died", philo);
			//обработать корректный выход из функции
		}
		else
		{
			pthread_mutex_unlock(&entry_point);
			philo_eat(args);
			pthread_mutex_lock(&entry_point);
			print_message("is sleeping", philo);
			pthread_mutex_unlock(&entry_point);
			ft_usleep(args->input->time_to_sleep);
			pthread_mutex_lock(&entry_point);
			print_message("is thinking", philo);
			pthread_mutex_unlock(&entry_point);
			//счетчик, чтобы лишний раз не вызывать lock/unlock (?)
		}
	}

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
	t_table	table;
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
	// init_philo(&philo[i], i + 1, &table->forks[0], &table->forks[0]);
	while (++i < input.num_of_philo - 1)
		init_philo(&philo[i], i + 1, &table.forks[i], &table.forks[i + 1]);
	//раздавать вилки четным/нечетным
	if (input.num_of_philo > 1)
		init_philo(&philo[i], i + 1, &table.forks[i], &table.forks[0]);
	// i = -1;
	// while (++i < input.num_of_philo)
	// {
	// 	printf("%p\n", philo[i]->forks->left_fork);
	// 	printf("%p\n", philo[i]->forks->right_fork);
	// }
	//exit(0);
	args = init_all_args(philo, &input);
	start = 0;
	pthread_exec(args, input.num_of_philo);
	//создать переменную, которая будет принимать значение true/false, если кто то умер
	//записать id философа, который умер - вывести сообщение
	//int i;

	// i = -1;
	// while (!args[i].death)
	// {
	// 	i = -1;
	// 	while (args[++i].philo)
	// 		;
	// }
	//отдельный поток на отслеживание смерти
	//pthread_create(&args->death, NULL, check_dead, (void *)args);
	//pthread_join(args->death, NULL);
	//free philo
	//free forks
	//free
	return (1);
}