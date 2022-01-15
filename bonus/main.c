#include "philo_bonus.h"

void	print_message(char *str, t_philo *philo)
{
	sem_wait(philo->sem[SEM_PRINT]);
	ft_putnbr_fd(get_time(philo->time_start), 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);	
	sem_post(philo->sem[SEM_PRINT]);
}

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->sem[SEM_FORKS]);
	print_message("has taken first a fork\n", philo);
	sem_wait(philo->sem[SEM_FORKS]);
	print_message("has taken seconde a fork\n", philo);
	print_message("is eating\n", philo);
	philo->time_last_eat = get_time(0);
	philo->current_count_eat += 1;
	ft_usleep(philo->input->time_to_eat);
	sem_post(philo->sem[SEM_FORKS]);
	sem_post(philo->sem[SEM_FORKS]);
}

void	*monitoring_death(void *v_philo)
{
	t_philo *philo;

	philo = (t_philo *)v_philo;
	while (1)
	{
		if (get_time(0) - philo->time_last_eat > philo->input->time_to_die)
		{
			sem_wait(philo->sem[SEM_DEAD]);
			print_message("is dead\n", philo);
			sem_wait(philo->sem[SEM_PRINT]);
			exit(1);
		}
	}
	return NULL;
}


void	philo_life(t_philo *philo)
{
	pthread_t	pt_death;

	pthread_create(&pt_death, NULL, &monitoring_death, philo);
	pthread_detach(pt_death);
	while (1)
	{
		if (philo->input->max_count_eat != -1 && philo->current_count_eat == philo->input->max_count_eat)
			exit(2);
		philo_eat(philo);
		print_message("is sleeping\n", philo);
		ft_usleep(philo->input->time_to_sleep);
		print_message("is thinking\n", philo);
	}
}

void	wait_processes(t_philo *philo, int cur_count, int count)
{
	int	i;
	int	status;
	
	i = -1;
	waitpid(0, &status, WUNTRACED);
	if (WEXITSTATUS(status) == 1)
	{
		while (++i < count)
				kill(philo[i].pid, SIGKILL);
	}
	else if (WEXITSTATUS(status) == 2)
	{
		if (cur_count == 0)
			while (++i < count)
				kill(philo[i].pid, SIGKILL);
		else
			wait_processes(philo, --cur_count, count);
	}
}

int	main(int argc, char **argv)
{
	t_input	*input_data;
	t_philo	*philo;
	int i;
	int	count;

	count = ft_atoi(argv[1]);
	validate_data(argc, argv);
	philo = init(argv, argc);
	i = -1;
	while (++i < count)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			return (0);
		if (!philo[i].pid)
			philo_life(&philo[i]);
	}
	wait_processes(philo, count, count);
	while (1)
		;
	return 0;
}