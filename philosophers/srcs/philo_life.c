/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:33:16 by troxanna          #+#    #+#             */
/*   Updated: 2022/01/16 16:20:01 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_dead(t_philo *philo)
{
	print_message("died\n", philo);
	pthread_mutex_lock(philo->message);
	philo->input->end = 1;
}

void	monitoring_death(t_philo *philo, int count)
{
	int	i;
	int	tmp_count;

	while (!philo[0].input->end)
	{
		i = -1;
		tmp_count = 0;
		while (++i < count)
		{
			if (get_time(0) - philo[i].time_last_eat
				> philo[i].input->time_to_die)
			{
				philo_dead(&philo[i]);
				break ;
			}
			if (philo[i].input->max_count_eat != -1
				&& philo[i].current_count_eat == philo[i].input->max_count_eat)
			{
				if (++tmp_count == count)
					philo[0].input->end = 1;
				if (tmp_count == count)
					break ;
			}
		}
	}
}

static void	philo_eat(t_philo *philo, size_t r_fork, size_t l_fork)
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
	t_mutex	*forks;

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
	return (NULL);
}
