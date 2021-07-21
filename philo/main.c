#include "includes/philo.h"
#include <stdio.h>
volatile int start;
//int start;
//mutex для блокировки взятия вилок
pthread_mutex_t entry_point = PTHREAD_MUTEX_INITIALIZER;



void	print_message(char *str, t_philo *philo)
{
	long current_time;

	//pthread_mutex_lock(&entry_point);
	pthread_mutex_lock(&entry_point);
	current_time = get_time(philo->start);
	if (start > 0)
	{
		ft_putnbr_fd(current_time, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(philo->id, 1);
		ft_putchar_fd(' ', 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
		pthread_mutex_unlock(&entry_point);	
	}
	//pthread_mutex_unlock(&entry_point);
	// timestamp_in_ms X message
	//текущее время
	//id философа
	// сообщение (is eating, is sleeping, is thinking, has taken a fork, died)
}

void	philo_eat(t_all **arg, mutex_t *first_fork, mutex_t *second_fork)
{
	//сделать, чтобы ели только четные/нечетные философы
	//
	// if ((*arg)->philo->id % 2 && (*arg)->philo->id != (*arg)->input->num_of_philo)
	// {
		//printf("id philo %d\n", )
		//write(1, "test odd\n", 11);
		pthread_mutex_lock(first_fork);
		// pthread_mutex_lock(&entry_point);
		// printf("%p\n", first_fork);
		// pthread_mutex_unlock(&entry_point);
		print_message("has taken first a fork", (*arg)->philo);
		pthread_mutex_lock(second_fork);
		// pthread_mutex_lock(&entry_point);
		// printf("%p\n", second_fork);
		// pthread_mutex_unlock(&entry_point);
		print_message("has taken second a fork", (*arg)->philo);
		print_message("is eating", (*arg)->philo);
		(*arg)->philo->count_eat++;
		(*arg)->philo->last_eat = get_time(0);
		ft_usleep((*arg)->input->time_to_eat);
		print_message("eating end", (*arg)->philo);
		//pthread_mutex_lock(&entry_point);
		//(*arg)->philo->count_eat++;
		//подумать как нормально можно сделать
		pthread_mutex_unlock(first_fork);
		usleep(100);
		//ft_usleep(1);
			//ft_usleep(1);
		//pthread_mutex_lock(&entry_point);
		//printf("fork free %p\n", second_fork);
		//pthread_mutex_unlock(&entry_point);
		//printf("right fork free %p\n", (*arg)->philo->right_fork);
		//pthread_mutex_lock(&entry_point);
		pthread_mutex_unlock(second_fork);
		//pthread_mutex_unlock(&entry_point);
		//pthread_mutex_lock(&entry_point);
		//printf("fork free %p\n", first_fork);
		//pthread_mutex_unlock(&entry_point);
		//printf("left fork free %p\n", (*arg)->philo->left_fork);
	//}
	// if (arg->philo->id % 2)
	// {
	// 	pthread_mutex_lock(arg->philo->right_fork);
	// 	print_message("has taken right a fork", arg->philo);
	// }
	// else
	// {
	// 	pthread_mutex_lock(arg->philo->left_fork);
	// 	print_message("has taken left a fork", arg->philo);
	// }

	//ft_usleep(10)

}

void	*life_philo(void *arg)
{
	t_all *args;
	t_philo	*philo;
	
	args = (t_all *)arg;
	philo = args->philo;
	while (!start)
		;
	philo->last_eat = get_time(0);
	//printf("%ld\n", )
	philo->start = get_time(0);
	while (start != -1)
	{
		//разобраться, почему с нечетным количеством философов предпоследний не берет вилки
		//write(1, "test\n", 5);
		//pthread_mutex_lock(&entry_point);
		if (philo->id % 2)
		{
			write(1, "test even\n", 10);
			philo_eat(&args, philo->right_fork, philo->left_fork);
		}
		else if (!(philo->id % 2) || (philo->id == args->input->num_of_philo && philo->id % 2))
		{
			write(1, "odd even\n", 10);
			philo_eat(&args, philo->left_fork, philo->right_fork);
		}
		//pthread_mutex_unlock(&entry_point);
		print_message("is sleeping", philo);
		ft_usleep(args->input->time_to_sleep);
		print_message("is thinking", philo);
		//счетчик, чтобы лишний раз не вызывать lock/unlock (?)
	}

}

void	check_death_and_eat(t_all **arg, int count, int count_eat)
{
	t_all **args;
	t_philo	*philo;
	int i;

	args = (t_all **)arg;
	//int i = -1;
	//printf("start == %d\n", start);
	while (start != -1)
	{
		i = -1;
		while (++i < count)
		{
			if ((*args)[i].philo->count_eat == count_eat)
			{
				start = -1;
				int j = -1;
				while (++j < count)
					pthread_detach((*args)[j].philo->pt);
			}
			if ((*args)[i].philo->last_eat &&
				(get_time(0) - (*args)[i].philo->last_eat) > (*args)->input->time_to_die)
			{
				start = -1;
				//printf("last eat time == %ld\n", get_time(0) - (*args)[i].philo->last_eat);
				//printf("dead time == %ld\n", get_time((*args)[i].philo->start));
				//printf("id == %d\n", (*args)[i].philo->id);
				////костыльно как то, подумать
				//write(1, "died\n", 5);
				int j = -1;
				while (++j < count)
					pthread_detach((*args)[j].philo->pt);
				//return ;
			}
		}
	}
	// while (1)
	// {
	// 	if (get_time(0) - philo->last_eat >= args->input->time_to_die)
	// 	{
	// 		start = 2;
	// 		write(1, "died\n", 5);
	// 		//print_message("died", philo);
	// 		//обработать корректный выход из функции
	// 	}
	// }
	//philo = args->philo;
	// pthread_mutex_lock(&entry_point);
	// printf("%d = %ld\n", philo->id, get_time(0) - philo->last_eat);
	// if (get_time(0) - philo->last_eat >= args->input->time_to_die)
	// {
	// 	start = 2;
	// 	write(1, "died\n", 5);
	// 	//print_message("died", philo);
	// 	//обработать корректный выход из функции
	// }
}

void	pthread_exec(t_all *args, int count, int count_eat)
{
	int	i;
	pthread_t die;

	i = -1;
	//pthread_create(&die, NULL, check_death, &args);
	while (++i < count)
	{
		pthread_create(&args[i].philo->pt, NULL, life_philo, &args[i]);	
	}
	start = 1;
	check_death_and_eat(&args, count, count_eat);
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
	i = 0;
	init_table(&table, input.num_of_philo);
	// init_philo(&philo[i], i + 1, &table->forks[0], &table->forks[0]);
	init_philo(&philo[0], 1, &table.forks[0], &table.forks[1]);
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
	pthread_exec(args, input.num_of_philo, input.count_eat);
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