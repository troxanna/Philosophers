/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:25:19 by troxanna          #+#    #+#             */
/*   Updated: 2022/01/16 18:28:31 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_input	*init_input(char **argv, int argc)
{
	t_input	*data;

	data = (t_input *)malloc(sizeof(t_input));
	if (!data)
		return (NULL);
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

static t_mutex	*init_forks(int count)
{
	t_mutex	*forks;
	int		i;

	i = -1;
	forks = (t_mutex *)malloc(sizeof(t_mutex) * count);
	if (!forks)
		return (NULL);
	while (++i < count)
		if (pthread_mutex_init(&(forks[i]), NULL))
			return (NULL);
	return (forks);
}

static t_mutex	*init_message(void)
{
	t_mutex	*message;

	message = (t_mutex *)malloc(sizeof(t_mutex));
	if (!message)
		return (NULL);
	if (pthread_mutex_init(message, NULL))
		return (NULL);
	return (message);
}

static void	init_philo(t_philo *philo, int id, size_t l_fork, size_t r_fork)
{
	philo->id = id;
	philo->left_fork = l_fork;
	philo->right_fork = r_fork;
}

t_philo	*init(char **argv, int argc)
{
	t_input	*input;
	t_mutex	*forks;
	t_mutex	*message;
	t_philo	*philo;
	int		i;

	input = init_input(argv, argc);
	forks = init_forks(input->num_of_philo);
	philo = (t_philo *)malloc(sizeof(t_philo) * input->num_of_philo);
	message = init_message();
	if (!forks || !philo || !message || !input)
		return (ft_error(1));
	i = -1;
	while (++i < input->num_of_philo)
	{
		if (i == 0)
			init_philo(&philo[i], i + 1, i, input->num_of_philo - 1);
		else
			init_philo(&philo[i], i + 1, i, i - 1);
		philo[i].forks = forks;
		philo[i].current_count_eat = 0;
		philo[i].message = message;
		philo[i].input = input;
	}
	return (philo);
}
