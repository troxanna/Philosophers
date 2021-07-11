#include "../includes/philo.h"

void	init_philo(mutex_t *l_fork, mutex_t *r_fork, char *name, int id)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		ft_error(1);
	philo->left_fork = l_fork;
	philo->right_fork = r_fork;
	philo->name = ft_strdup(name);
	philo->id = 0;
}

void	free_philo(t_philo *philo)
{
	if (!philo)
		return ;
	free(philo->name);
	free(philo);
}

t_input	*init_input(int n_philo, int t_die, int t_eat, int t_sleep)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	if (!input)
		ft_error(1);
	input->num_of_philo = n_philo;
	input->time_to_die = t_die;
	input->time_to_eat = t_eat;
	input->time_to_sleep = t_sleep;
	input->count_eat = -1;
	return (input);
}

