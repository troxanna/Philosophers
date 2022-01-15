#include "philo.h"

int start = 1;

void	print_message(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->message);
	ft_putnbr_fd(get_time(philo->time_start), 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	pthread_mutex_unlock(philo->message);	
}

void	monitoring_death(t_philo *philo)
{
	int i;
	int	tmp_count;
	int count;

	count = philo[0].input->num_of_philo;
	while (!philo[0].input->end)
	{
		i = -1;
		tmp_count = 0;
		while (++i < count)
		{
			if (get_time(0) - philo[i].time_last_eat > philo[i].input->time_to_die)
			{
				print_message( "died\n", &philo[i]);
				pthread_mutex_lock(philo->message);
				philo[0].input->end = 1;
				break ;
			}
			if (philo[i].input->max_count_eat != -1 && philo[i].current_count_eat >= philo[i].input->max_count_eat)
			{
				tmp_count += 1;
				if (tmp_count == count)
				{
					philo[0].input->end = 1;
					break ;
				}
			}
		}
	}
}

void	philo_eat(t_philo *philo, size_t r_fork, size_t l_fork)
{
	pthread_mutex_lock(&philo->forks[l_fork]);
	print_message("has taken first a fork\n", philo);
	pthread_mutex_lock(&philo->forks[r_fork]);
	print_message("has taken seconde a fork\n", philo);
	print_message("is eating\n", philo);
	philo->current_count_eat += 1;
	philo->time_last_eat = get_time(0);
	ft_usleep(philo->input->time_to_eat);
	pthread_mutex_unlock(&philo->forks[l_fork]);
	pthread_mutex_unlock(&philo->forks[r_fork]);
}

void	*philo_life(void *v_philo)
{
	t_philo	*philo;
	mutex_t	*forks;
	philo = (t_philo *)v_philo;
	forks = philo->forks;
	pthread_detach(philo->pt);
	if (philo->input->num_of_philo == 1)
	{
		print_message("has taken first a fork\n", philo);
		ft_usleep(philo->input->time_to_die);
	}
	if (philo->id % 2 != 0)
		ft_usleep(philo->input->time_to_eat);
	while (!philo->input->end)
	{
		philo_eat(philo, philo->right_fork, philo->left_fork);
		print_message("is sleeping\n", philo);
		ft_usleep(philo->input->time_to_sleep);
		print_message("is thinking\n", philo);
	}
	return NULL;
}


int	main(int argc, char **argv)
{
	t_input	*input_data;
	t_philo	*philo;
	int i;

	validate_data(argc, argv);
	philo = init(argv, argc);
	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philo[i].time_start = get_time(0);
		pthread_create(&philo[i].pt, NULL, &philo_life, &philo[i]);
	}
	monitoring_death(philo);
	return 0;
}